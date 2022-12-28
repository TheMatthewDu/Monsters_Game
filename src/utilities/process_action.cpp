#include <string>

#include "process_action.hpp"
#include "server_helpers.hpp"

using namespace std;

void generate_message(int fd, char action, string msg){
    string send = action + msg;
    char *char_msg = (char *) send.c_str();
    
    int size = msg.length() + 2;
    Write(fd, &size, sizeof(int));
    Write(fd, char_msg, msg.length() + 2);
}

tuple<char, string> read_message(int fd){
    int msg_size;
    Read(fd, &msg_size, sizeof(int));

    char read_msg[msg_size];
    
    int num_read = Read(fd, read_msg, msg_size);

    cerr << "Message Read. Length " << to_string(num_read) << endl;

    char flag = read_msg[0];
    string msg = string(&(read_msg[1]));    
    return tuple<char, string>(flag, msg);
}