#pragma once
#include <Graphics/Sprite.h>
class Shot :
	public Jangine::Sprite
{
public:
	Shot(double angle, int x, int y, const char* path);
	~Shot();
	void update(float timestep);
private:
	double m_angle;
	float x, y, rotation;
};

class EnemyShot :
	public Shot
{
public:
	EnemyShot(double angle, int x, int y, const char* path);
};

