#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>

#include "read_file.hpp"

using namespace std;

Monster get_monster(string monster){
    if (monster == "Vaporeon"){
        return Vaporeon();
    } else if (monster == "Flareon"){
        return Flareon();
    } else if (monster == "Leafeon"){
        return Leafeon();
    } else if (monster == "Jolteon"){
        return Jolteon();
    } 
    else {
        cerr << "Invalid monster" << endl;
        exit(1);
    }
}

char get_move_type(string move_type){
    if (move_type == "Water"){
        return WATER;
    } else if (move_type == "Fire"){
        return FIRE;
    } else if (move_type == "Grass"){
        return GRASS;
    } else if (move_type == "Electric"){
        return ELECTRIC;
    } else {
        cerr << "Invalid move type" << endl;
        exit(1);
    }
}

char get_move_category(string move_category){
    if (move_category == "S"){
        return SPECIAL;
    } else {
        return PHYSICAL;
    }

}

vector<string> split(string str, char del){
    string temp = "";

    vector<string> string_vector;

    for (int i = 0; i < (int) str.size(); i++){
        if (str[i] != del){
            temp += str[i];
        } else {
            string_vector.push_back(temp);
            temp = "";
        }
    }
    
    string_vector.push_back(temp);
    return string_vector;
}

string strip(string line){
    int space_index = line.find_first_of(' ');
    int r_index = line.find_first_of('\r');
    int strip_index;
    if (space_index == -1 and r_index == -1){
        strip_index = line.size();
    } else if (space_index == -1) {
        strip_index = r_index;
    } else if (r_index == -1){
        strip_index = space_index;
    } else {
        strip_index = min(space_index, r_index);
    }

    return line.substr(0, strip_index);
}

vector<Monster> read_data(string filename){
	string line_data;
	ifstream file(filename);
    if (file.fail()){
        cerr << "File " << filename << " not found" << endl;
        exit(1);
    }

    vector<Monster> team;

    while (getline(file, line_data)) {
        Monster monster = get_monster(strip(line_data));

        for (int n = 0; n < 4; n++){
            getline(file, line_data);
            vector<string> spliced = split(line_data, ' ');
            
            char m_category = get_move_category(strip(spliced[3]));
            char m_type = get_move_type(spliced[2]);

            monster.set_moves(spliced[0], m_type, (spliced[1])[0], m_category);
        }

        team.push_back(monster);
        getline(file, line_data); // Remove spacer
	}

	// Close the file
	file.close();

    return team;
}
