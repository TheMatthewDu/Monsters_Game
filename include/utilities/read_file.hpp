#ifndef READ_DATA_HPP
#define READ_DATA_HPP

#include <vector>

#ifndef COKEMON_MONSTER_HPP
#include "Monster.hpp"
#endif // COKEMON_MONSTER_HPP

#ifndef PK_VAPOREON
#include "Vaporeon.hpp"
#endif

#ifndef PK_LEAFEON
#include "Leafeon.hpp"
#endif

#ifndef PK_FLAREON
#include "Flareon.hpp"
#endif

#ifndef PK_JOLTEON
#include "Jolteon.hpp"
#endif

vector<Monster> read_data(string filename);

#endif // READ_DATA_HPP
