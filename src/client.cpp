#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <tuple>

#include "client.hpp"
#include "server_helpers.hpp"
#include "process_action.hpp"

#define PORT 30000

using namespace std;

GamePlayer::GamePlayer(int _id){
    server_fd = Socket(PF_INET, SOCK_STREAM, 0);
	player_id = _id;
}

void GamePlayer::connect_to_server(){
    struct sockaddr_in server;
	server.sin_family = AF_INET; // Sets the family of socket
	server.sin_port = htons(PORT); // Port number in network order
	memset(&server.sin_zero, 0, 8); // Extra Padding; makes sockaddr_in same size as sockaddr struct.
	
	struct addrinfo *ai;
	char hostname[] = "localhost";
	
	/* this call declares memory and populates ailist */
	getaddrinfo(hostname, NULL, NULL, &ai);
	/* we only make use of the first element in the list */
	server.sin_addr = ((struct sockaddr_in *) ai->ai_addr)->sin_addr;
	
	// free the memory that was allocated by getaddrinfo for this list
	freeaddrinfo(ai);

    Connect(server_fd, (struct sockaddr *)&server, sizeof(struct sockaddr_in));
    
	Write(server_fd, &player_id, sizeof(int));
	cout << "Connected. Waiting for other players to join" << endl;
}

void GamePlayer::run(){
	bool running = true;
	while (running){
		tuple<char, string> msg = read_message(server_fd);
		if (get<0>(msg) == DISPLAY){
			cout << get<1>(msg) << endl;
		} else if (get<0>(msg) == CHOOSE) {
			cout << get<1>(msg) << endl;
			cout << "> ";
			string response;
			cin >> response;

			generate_message(server_fd, ATTACK, response);
			cout << "Recieved " << response << endl;
		} else if (get<0>(msg) == BREAK){
			running = false;
		} else{
			cerr << "client: Invalid Message" << endl;
			exit(1);
		}
	}
}

