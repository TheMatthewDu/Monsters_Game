/**
 * @file Monster.hpp
 * @author Matthew Du (matthewrhdu2@gmail.com)
 * @brief An abstract class for all monsters for this game
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef COKEMON_MONSTER_HPP
#define COKEMON_MONSTER_HPP
#include <string>
#include <vector>

#include "damage_table.hpp"

using namespace std;

/**
 * @brief A monster move struct for holding information about the information of a move that a monster can use 
 */
class Move {
    public: string name; // The name of the move
    public: char type; // The type of the move
    public: char category; // The category of the move
    public: int power; // The power of the move

    public: Move(string _name, char _type, char _category, int _power){
        name = _name;
        type = _type;
        category = _category;
        power = _power;
    }
};

/**
 * @brief An abstract monster object
 * 
 */
class Monster {
    public: string name; // The name of the monster
    public: int Level; // The level of the monster
    public: int HP; // The current Hit Points of the monster
    public: int Attack; // The attack statistic of the monster
    public: int Defense; // The defense statistic of the monster
    public: int Special_Attack; // The special attack statistic of the monster
    public: int Special_Defense; // The special defence statistic of the monster
    public: int Speed; // The speed of the monster
    public: char PkType; // The type of the monster (use type Macros)
    public: vector<Move> moves; // The array of moves that the monster can use
    private: int Damage_taken; // The amount of damage that has been incurred on the monster

    public: Monster();

    public: Monster(int hp, int atk, int def, int spe_atk, int spe_def, int spd, char pktype, string pkname);

    public: void take_damage(Monster attacker, Move move);

    public: void set_moves(string name, const char type, int power, char category);

    public: int get_percentage();

    public: vector<string> get_move_names();
};

int get_damage(Monster attacking, Monster defending, Move move);

#endif // COKEMON_MONSTER_HPP
