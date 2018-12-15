#pragma once
#include <Game States/GameState.h>
#include <Graphics/Sprite.h>
#include <iostream>
#include <SDL_mixer.h>
#include <list>
#include "Shot.h"
#include "Enemy.h"

class MainMenu :
	public Jangine::GameState
{
public:
	MainMenu(const std::string& msg, int count);
	~MainMenu();
	void draw() override;
	void update(float timestep) override;
private:
	Jangine::Sprite player;
	Jangine::Sprite arms;
	Jangine::Sprite bgSprite;
	SDL_Point pivot; //10,13
	float pX, pY;
	double yVel;
	std::list<Shot*> shots;
	std::list<Enemy*> enemies;
	Jangine::Timer timer;
	Mix_Chunk* sound;
	int spawnTime;
};

