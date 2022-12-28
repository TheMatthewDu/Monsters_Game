#include "server.hpp"

int main() {
	GameServer server = GameServer();
	server.accept_clients();
	server.play();
	return 0;
}