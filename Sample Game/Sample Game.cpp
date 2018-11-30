// Sample Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Jangine.h>
#include "MainMenu.h"

int main(int argc, char* args[])
{

	std::string s = R"he(
                      _____
                   ,-'     `._
                 ,'           `.        ,-.
               ,'               \       ),.\
     ,.       /                  \     /(  \;
    /'\\     ,o.        ,ooooo.   \  ,'  `-')
    )) )`. d8P"Y8.    ,8P"""""Y8.  `'  .--"'
   (`-'   `Y'  `Y8    dP       `'     /
    `----.(   __ `    ,' ,---.       (
           ),--.`.   (  ;,---.        )
          / \O_,' )   \  \O_,'        |
         ;  `-- ,'       `---'        |
         |    -'         `.           |
        _;    ,            )          :
     _.'|     `.:._   ,.::" `..       |
  --'   |   .'     """         `      |`.
        |  :;      :   :     _.       |`.`.-'--.
        |  ' .     :   :__.,'|/       |  \
        `     \--.__.-'|_|_|-/        /   )
         \     \_   `--^"__,'        ,    |
   -hrr- ;  `    `--^---'          ,'     |
          \  `                    /      /
           \   `    _ _          /
            \           `       /
             \           '    ,'
              `.       ,   _,'
                `-.___.---'
)he";

	std::cout << "Sample Game" << std::endl;

	Jangine::GameSettings::setDimensions(800, 600);
	auto game = new Jangine::GameEngine("Sample game");
	game->SetFirstState<MainMenu>(s, 1);
	game->Run();

	delete game;

	return 0;
}

