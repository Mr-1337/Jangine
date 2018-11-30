#pragma once
#include <Game States/GameState.h>
#include <Graphics/Sprite.h>
#include <iostream>


class MainMenu :
	public Jangine::GameState
{
public:
	MainMenu(const std::string& msg, int count);
	~MainMenu();
	void draw() override;
	void update() override;
	Jangine::Sprite sprite;
};

