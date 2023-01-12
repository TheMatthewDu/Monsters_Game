# Monsters Game
A command line version of the Pokémon game using TCP socket connections

## Setup
To download the code from this repository, run
```commandline
git clone https://github.com/TheMatthewDu/Monsters_Game.git
```

This project is compiled using `CMake` **ON LINUX/UNIX OPERATING SYSTEMS (including macOS) ONLY**. To build,
```commandline
mkdir build
cd build
cmake ..
make -j4
cd ..
```

## Playing the Game
To play the game, 
1. Open three (3) terminals on the same machine with access to the built code from this repository
2. On one of the terminals, run `./PkMonsters` to launch the server
3. On each of the other terminals, run `./Pkplayer <player number>`, where `<player number>` corresponds to the `data/player<player number>.txt` file
   1. Currently, there are two example files in that folder with numbers 123 and 234

## Game Features
Currently, the game only supports choosing monsters to put into play and choosing attacks. It is still very early in 
the game's development, and the repository is only public for the purposes of demonstrating proficiency in the C/C++ 
programming languages. 

Future iterations of the game involves adding more features, such as allowing switching monsters and introducing more 
variety of monsters which will (hopefully) make the game more closely resemble the actual Pokémon Game.



