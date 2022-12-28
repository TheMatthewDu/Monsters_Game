#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "Monster.hpp"

class GameBoard {
public:
    Monster monsters[2]; // Implemented using indices. 0 for player 1, 1 for player 2

    public: GameBoard();

    public: void set_player_monster(int player_num, Monster monster);

    public: std::string print_player_options(int player_num);

    public: std::string print_game();

    public: void process_attack(int player, int move_index);
};

#endif // GAMEBOARD_HPP