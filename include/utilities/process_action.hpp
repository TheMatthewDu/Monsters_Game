#include <iostream>
#include <tuple>

using namespace std;

// Server to client actions
#define CHOOSE 0
#define DISPLAY 1
#define BREAK 100

// Client to server actions
#define ATTACK 50

void generate_message(int fd, char action, string msg);

tuple<char, string> read_message(int fd);
