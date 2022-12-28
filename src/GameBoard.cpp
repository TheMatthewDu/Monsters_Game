#include <iostream>

#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard(){};

void GameBoard::set_player_monster(int player_num, Monster monster){
    if (player_num > 2){
        cerr << "Invalid Player Number" << endl;
        exit(1);
    }

    cout << "Setting " << monster.name << endl;
    monsters[player_num] = monster;
}

string GameBoard::print_game(){
    return string("=== Current State === \n") + 
    "Player 1: " + monsters[0].name + " with " + to_string(monsters[0].get_percentage()) + "% HP\n" + 
    "Player 2: " + monsters[1].name + " with " + to_string(monsters[1].get_percentage()) + "% HP\n";
}

string GameBoard::print_player_options(int player_num){
    vector<string> list_of_moves = (monsters[player_num]).get_move_names();
    string acc = "Current Monster: " + monsters[player_num].name + "\n";
    for (int i = 0; i < list_of_moves.size(); i++){
        acc = acc + to_string(i) + ": " + list_of_moves[i] + "\n";
    }

    return acc;
}

void GameBoard::process_attack(int player, int move_index){
    monsters[1 - player].take_damage(monsters[player], monsters[player].moves[move_index]);
}
