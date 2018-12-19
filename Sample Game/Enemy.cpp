#include "Enemy.h"
#include <Util/Logger.h>


Enemy::Enemy(std::list<Shot*> &shots, SDL_Rect* player) :
	m_shots(shots), player(player), m_renderer(Jangine::Globals::getRenderer())
{
	m_sprite.load("heavy.png");
	top.load("heavytop.png");
	sound = Mix_LoadWAV("shoot.wav");
	int death = rand() % 3 + 1;
	std::string file = "die" + std::to_string(death); 
	file += ".wav";
	deathSound = Mix_LoadWAV(file.c_str());
	m_sprite.Scale(0.3);
	top.Scale(0.3);
	y = 430;
	x = 300;
	hp = 500;
	angle = 0;
	timer.start();
}

void Enemy::update(float timestep)
{
	if (timer.getTicks() % 100 == 0)
	{
		dir = rand() % 3;
	}
	m_sprite.setX(x);
	m_sprite.setY(y);
	top.setX(x);
	top.setY(y);
	SDL_Rect *rect = m_sprite.getRect();
	SDL_Rect it;
	for (auto s : m_shots)
	{
		auto p = dynamic_cast<EnemyShot*>(s);
		if (p == nullptr && SDL_IntersectRect(rect, s->getRect(), &it))
		{
			hp--;
		}
	}

	switch (dir)
	{
	case 0:
		xVel = 300.0f;
		break;
	case 1:
		xVel = -300.0f;
		break;
	case 2:
		xVel = 0;
		break;
	}

	x += xVel * timestep;

	if (x > 800)
		dir = 1;
	if (x < 0)
		dir = 0;

	angle = std::atan2(player->y - y, player->x - x);
	SDL_Point pivot = { 184.0 * 0.3, 262.0 * 0.3 };

	if (player->x > x)
	{
		pivot.x -= 20;
		m_sprite.setFlip(SDL_FLIP_HORIZONTAL);
		top.setFlip(SDL_FLIP_HORIZONTAL);
		top.rotate(angle * 180 / M_PI, &pivot);
	}

	if (player->x < x)
	{
		m_sprite.setFlip(SDL_FLIP_NONE);
		top.setFlip(SDL_FLIP_NONE);
		top.rotate(angle * 180 / M_PI - 180, &pivot);
	}

	if (timer.getTicks() > 500)
	{
		timer.restart();
		Mix_PlayChannel(-1, sound, 0);
		m_shots.push_back(new EnemyShot(angle, x, y, "shot2.png"));
	}

	bar.x = x;
	bar.y = y - 10;
	bar.w = 50 * (float)hp / 500;
	bar.h = 8;

	if (hp < 0)
		die();

}

void Enemy::draw()
{
	m_sprite.draw();
	top.draw();
	SDL_SetRenderDrawColor(m_renderer, 230, 20, 20, 255 );
	SDL_RenderFillRect(m_renderer, &bar);
}


void Enemy::die()
{
	Mix_PlayChannel(-1, deathSound, 0);
	dead = true;
}


Enemy::~Enemy()
{
}