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


void Shot::update()
{
	x += 5 * std::cos(m_angle);
	y += 5 * std::sin(m_angle);
	rotation += 3.3f;
	SDL_Point point = { 10, 10 };
	rotate(rotation, &point);
	setX(x);
	setY(y);
}

EnemyShot::EnemyShot(double angle, int x, int y, const char* path) :
	Shot(angle, x, y, path)
{

}