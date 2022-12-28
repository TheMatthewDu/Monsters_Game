class GamePlayer {
    private: int server_fd;
    private: int player_id;
    
    public: GamePlayer(int _id);

    public: void connect_to_server();

    public: void run();
};