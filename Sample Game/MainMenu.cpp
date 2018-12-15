#include "MainMenu.h"
#include <Util/Logger.h>

MainMenu::MainMenu(const std::string& msg, int count)
{
	for (int i = 0; i < count; i++)
	{
		Jangine::Logger::Log(msg);
	}

	player.load("guy.png");
	arms.load("arms.png");
	bgSprite.load("rtx.png");
	pivot = { 10, 13 };
	sound = Mix_LoadWAV("nope.wav");
	enemies.push_back(new Enemy(shots, player.getRect()));
	timer.start();

	spawnTime = 20000;

}


MainMenu::~MainMenu()
{
	Mix_FreeChunk(sound);
}


void MainMenu::update(float timestep)
{
	int x, y;
	auto b = SDL_GetMouseState(&x, &y);
	double angleRad = std::atan2(y - pY, x - pX);
	arms.rotate(angleRad * 180 / M_PI, &pivot);
	yVel += 980.0f * timestep;
	pY += yVel * timestep;

	static bool lDown = false;

	if (timer.getTicks() > spawnTime)
	{
		enemies.push_back(new Enemy(shots, player.getRect()));
		timer.restart();
		spawnTime *= 0.8;
	}

	if (b & SDL_BUTTON_LMASK)
	{
		if (!lDown)
		{
			lDown = true;
			shots.push_back(new Shot(angleRad, pX, pY ,"shot.png"));
			Mix_PlayChannel(-1, sound, 0);
		}
	}
	else
	{
		lDown = false;
	}

	if (pY > 500)
	{
		pY = 500;
		yVel = 0;
	}

	const Uint8* keys = SDL_GetKeyboardState(nullptr);
	if (pY == 500 && keys[SDL_SCANCODE_W])
		yVel = -800.0f;
	if (keys[SDL_SCANCODE_D] && pX < 700)
		pX += 300.0f * timestep;
	if (keys[SDL_SCANCODE_A] && pX > 0)
		pX -= 300.0f * timestep;

	player.setX(pX);
	player.setY(pY);
	arms.setX(pX);
	arms.setY(pY);


	SDL_Rect* shotPos = shots.size() > 0 ? shots.back()->getRect() : nullptr;
	if (shotPos != nullptr && (shotPos->x > 900 || shotPos->x < -20 || shotPos->y > 620 || shotPos->y < -20))
	{
		delete shots.back();
		shots.pop_back();
	}

	for (auto s : shots)
	{
		s->update(timestep);

	}
	if (!enemies.empty())
	{
		for (auto &s : enemies)
		{
			if (s != nullptr)
			{
				s->update(timestep);
				if (s->dead)
				{
					delete s;
					s = nullptr;
				}
			}
		}
	}

}


void MainMenu::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	SDL_Rect r = { 0, 0, 60, 30 };
	bgSprite.draw();
	SDL_RenderFillRect(m_renderer, &r);
	player.draw();
	arms.draw();
	for (auto &s : shots)
	{
		s->draw();
	}
	for (auto s : enemies)
	{
		if(s != nullptr)
			s->draw();
	}
	SDL_RenderPresent(m_renderer);
}
