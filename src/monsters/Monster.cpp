/**
 * @file Monster.cpp
 * @author Matthew Du (matthewrhdu2@gmail.com)
 * @brief An abstract class for all monsters for this game
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

#include "Monster.hpp"

using namespace std;

/**
 * @brief Compute the damage done to the opposing monster.
 * 
 * @param other The opposing monster
 * @param move The move chosen for the attack
 * 
 * @return int The amount of damage done
 */
int get_damage(Monster attacking, Monster defending, Move move){
    // Computes the ratio of the damage done based on the move's category
    int category_based_damage;
    if (move.category == PHYSICAL){
        category_based_damage = attacking.Attack * move.power / attacking.Defense;
    } else {
        category_based_damage = attacking.Special_Attack * move.power / attacking.Special_Defense;
    }

    // Computes the Same Type Attack Bonus (STAB) damage done
    int STAB;
    if (attacking.PkType == move.type){
        STAB = 1.5;
    } else {
        STAB = 1;
    }

    double level_boost = 2 * attacking.Level / 5 + 2;
    double first_term = (level_boost * category_based_damage) / 50;
    cerr << (first_term + 2) * STAB * compute_type_matchup(attacking.PkType, defending.PkType) * (85 + rand() % 15) << endl;
    return (first_term + 2) * STAB * compute_type_matchup(attacking.PkType, defending.PkType) * (85 + rand() % 15);
}

Monster::Monster() {};

/**
 * @brief Construct a new Monster:: Monster object
 * 
 * @param hp The total hit points of the monster
 * @param atk The attack statistic of the monster
 * @param def The defense statistic of the monster
 * @param spe_atk The special attack statistic of the monster
 * @param spe_def The special defence statistic of the monster
 * @param spd The speed of the monster
 * @param pktype The type of the monster
 * @param pkname The name of the monster
 */
Monster::Monster(int hp, int atk, int def, int spe_atk, int spe_def, int spd, char pktype, string pkname){
    Level = 100;
    HP = hp;
    Attack = atk;
    Defense = def;
    Special_Attack = spe_atk;
    Special_Defense = spe_def;
    Speed = spd;
    PkType = pktype;
    Damage_taken = 0;
    name = pkname;
}

/**
 * @brief Set a move into a monster to an unoccupied index
 * 
 * @param name The name of the move
 * @param type The type of the move
 * @param power The power of the move
 * @param category The category of the move
 */
void Monster::set_moves(string name, const char type, int power, char category){
    Move move = Move(name, type, power, category);
    moves.push_back(move);
}

/**
 * @brief Take damage done to a monster
 * 
 * @param damage The damage done to a monster
 */
void Monster::take_damage(Monster attacker, Move move){
    Damage_taken += get_damage(attacker, *this, move);
}

/**
 * @brief Get the percentage of hit points remaining
 * 
 * @return int The amount of hit points remaining
 */
int Monster::get_percentage(){
    return (HP - Damage_taken) * 100 / HP;
}

vector<string> Monster::get_move_names(){
    vector<string> names;
    for (auto move : moves){
        names.push_back(move.name);
    }
    return names;
}