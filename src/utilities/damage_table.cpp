double compute_type_matchup(char attacking, char defending){
    double damage_table[4][4] = {
        {0.5, 0.5, 1.0, 1.5},
        {1.5, 0.5, 1.0, 0.5},
        {1.0, 1.5, 0.5, 0.5},
        {0.5, 1.5, 1.0, 0.5}
    };

    return damage_table[(int) attacking][(int) defending];
}