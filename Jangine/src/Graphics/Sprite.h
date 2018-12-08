#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "../Core/Platform.h"
#include "../Core/Globals.h"

namespace Jangine
{

	//Represents a drawable image
	class Sprite
	{
	public:
		Sprite();
		~Sprite();
		virtual void load(const std::string& path);
		virtual void draw();
		void draw(SDL_Rect& clip);
		void setX(int x);
		void setY(int y);
		void setAlpha(int alpha);
		void scale(double scaleFactor);
		void setWidthHeight(int w, int h);
		void getWidthHeight(int* w, int* h);
		void rotate(double angle, SDL_Point* pivot);
		void setFlip(SDL_RendererFlip flip);
		SDL_Rect* getRect();

	private:

	protected:
		SDL_Texture* m_texture;
		SDL_Renderer* m_renderer;
		SDL_Rect m_dstRect;
		SDL_RendererFlip m_flip;
		double angle;
		SDL_Point pivot;
	};

}