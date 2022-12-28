#include <vector>

#include "Monster.hpp"
#include "GameBoard.hpp"

using namespace std;

class GameServer {
    private: int sock_fd;
    private: int player_fds[2];
    private: int players_numbers[2]; // We are dealing with such little inputs that it's not practical to use a hash
    private: vector<Monster> teams[2];
    private: GameBoard board;
    private: fd_set all_fds;

    public: GameServer();

    public: void accept_clients();

    public: void play();

    private: void get_responses(tuple<char, string> *responses);
};