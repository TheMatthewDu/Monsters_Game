#include <iostream>
#include <cstring>
#include "client.hpp"

int main(int argc, char **argv) {
	if (argc != 2){
		std::cerr << "usage: " << argv[0] << " <player number>" << std::endl;
		exit(0);
	}

	GamePlayer player = GamePlayer((int) strtol(argv[1], NULL, 10));
	player.connect_to_server();
	player.run();
	return 0;
}