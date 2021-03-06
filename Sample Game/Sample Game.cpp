// Sample Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program is a basic demo showing how to use Jangine.

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
         ;  `    `--^---'          ,'     |
          \  `                    /      /
           \   `    _ _          /
            \           `       /
             \           '    ,'
              `.       ,   _,'
                `-.___.---'
)he";

	std::string d = R"he(
   ,--._ 
    `.   `.                      ,-. 
      `.`. `.                  ,'   ) 
        \`:  \               ,'    / 
         \`:  ),.         ,-' ,   / 
         ( :  |:::.    ,-' ,'   ,' 
         `.;: |::::  ,' ,:'  ,-' 
         ,^-. `,--.-/ ,'  _,' 
        (__        ^ ( _,' 
      __((o\   __   ,-' 
    ,',-.     ((o)  / 
  ,','   `.    `-- ( 
  |'      ,`        \ 
  |     ,:' `        | 
 (  `--      :-.     | 
 `,.__       ,-,'   ; 
 (_/  `,__,-' /   ,' 
 |\`--|_/,' ,' _,' 
 \_^--^,',-' -'( 
 (_`--','       `-. 
  ;;;;'       ::::.`------. 
    ,::       `::::  `:.   `. 
   ,:::`       :::::   `::.  \ 
  ;:::::       `::::     `::  \ 
  |:::::        `::'      `:   ; 
  |:::::.        ;'        ;   | 
  |:::::;                   )  | 
  |::::::        ,   `::'   |  \ 
  |::::::.       ;.   :'    ;   ::. 
  |::::,::        :.  :   ,;:   |:: 
  ;:::;`"::     ,:::  |,-' `:   |::, 
  /;::|    `--;""';'  |     :. (`";' 
  \   ;           ;   |     ::  `, 
   ;  |           |  ,:;     |  : 
   |  ;           |  |:;     |  | 
   |  |           |  |:      |  | 
   |  |           |  ;:      |  | 
  /___|          /____|     ,:__| 
 /    /          /    |     /    ) 
 `---'          '----'      `---' )he";

	std::cout << "Sample Game" << std::endl;

	//Set the dimensions of the application
	Jangine::GameSettings::setDimensions(800, 600);
	Jangine::Logger::SetOutputStream(std::cout);
	//Create the engine
	auto game = new Jangine::GameEngine("Sample game");
	//Set your first state. You must set the initial state BEFORE running the engine.
	game->SetFirstState<MainMenu>(s, 6);
	//RUN THE ENGINE!!! // Ok
	game->Run();

	delete game;

	return 0;
}

