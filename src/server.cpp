#include <iostream>
#include <cstring>

#include "server.hpp"
#include "server_helpers.hpp"
#include "read_file.hpp"
#include "process_action.hpp"

#define PORT 30000

using namespace std;

GameServer::GameServer() {
    sock_fd = Socket(PF_INET, SOCK_STREAM, 0);

    // Make sure we can reuse the port immediately after the
    // server terminates. Avoids the "address in use" error
    int on = 1;
    int status = Setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on));

    struct sockaddr_in addr;

    addr.sin_family = PF_INET;
    addr.sin_port = htons(PORT);
    memset(&(addr.sin_zero), 0, 8);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Associate the process with the address and a port
    Bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr));

    Listen(sock_fd, 10);

    FD_ZERO(&all_fds);
}

void GameServer::accept_clients(){
    for (int n = 0; n != 2; n++){
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(struct sockaddr_in);
        client_addr.sin_family = AF_INET;
        
        int player_fd = Accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);
                
        player_fds[n] = player_fd;
        FD_SET(player_fd, &all_fds);
        
        // Read Player Number
        Read(player_fd, &(players_numbers[n]), sizeof(int));

        string filename = "data/player" + to_string(players_numbers[n]) + ".txt";
        teams[n] = read_data(filename);

        board.set_player_monster(n, teams[n][0]);

        cout << "Player " << players_numbers[n] << " connected" << endl;
    }
}

void GameServer::get_responses(tuple<char, string> *responses){
    for (int i = 0; i < 2; i++){
        fd_set working = all_fds;
        Select(player_fds[1] + 1, &working, NULL, NULL, NULL);
        
        for (auto fd : player_fds){
            if (FD_ISSET(fd, &working)){
                tuple<char, string> message = read_message(fd);
                responses[i] = message;
            }
        }

    }
}

void GameServer::play(){
    for (int n = 0; n < 2; n++){
        cout << board.print_game() << endl;

        for (int i = 0; i < 2; i++){
            cerr << "Sending: " << board.print_player_options(i) << " to player " << to_string(player_fds[i]) << endl;
            generate_message(player_fds[i], DISPLAY, board.print_game());
            generate_message(player_fds[i], DISPLAY, board.print_player_options(i));
            generate_message(player_fds[i], CHOOSE, "Choose a move");
        }

        tuple<char, string> responses[2];
        get_responses(responses);

        for (int i = 0; i < 2; i++){
            if (get<0>(responses[i]) == ATTACK){
                board.process_attack(i, stoi(&get<0>(responses[i])));
            }
        }
    }

    cerr << "Terminating" << endl;
    generate_message(player_fds[0], BREAK, "");
    generate_message(player_fds[1], BREAK, "");
}
