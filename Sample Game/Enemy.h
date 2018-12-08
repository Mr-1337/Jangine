#pragma once

#include <list>
#include "Shot.h"
#include <SDL_mixer.h>
#include <Util/Timer.h>
#include <SDL.h>
#include <Core/Globals.h>

class Enemy
{
public:
	Enemy(std::list<Shot*> &shots, SDL_Rect* player);
	~Enemy();
	void update();
	void draw();
	bool dead;
private:
	float x, y, xVel;
	std::list<Shot*>& m_shots;
	Jangine::Sprite m_sprite;
	Jangine::Sprite top;
	Jangine::Timer timer;
	Mix_Chunk* sound;
	Mix_Chunk* deathSound;
	SDL_Renderer* m_renderer;
	SDL_Rect* player;
	SDL_Rect bar;
	int hp;
	double angle;
	int dir;
	void die();
};

