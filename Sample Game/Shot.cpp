#include "Shot.h"

Shot::Shot(double angle, int x, int y, const char* path) :
	m_angle(angle), x(x), y(y)
{
	load(path);
	rotation = 0;
}

Shot::~Shot()
{
}


void Shot::update(float timestep)
{
	x += 300.0f * std::cos(m_angle) * timestep;
	y += 300.0f * std::sin(m_angle) * timestep;
	rotation += 210.0f * timestep;
	SDL_Point point = { 10, 10 };
	rotate(rotation, &point);
	setX(x);
	setY(y);
}

EnemyShot::EnemyShot(double angle, int x, int y, const char* path) :
	Shot(angle, x, y, path)
{

}