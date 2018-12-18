#pragma once

#include <iostream>
#include <SDL_render.h>
#include <string>
#include "../Core/Platform.h"
#include "../Core/Globals.h"
#include "TextureManager.h"
#include "Texture.h"

namespace Jangine
{

	/*
		Represents a drawable object on the screen. It contains a Texture object
		which contains the raw image data. Sprites can have transformations applied to them
		and their position is integral (in pixels).
	*/
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
		void Scale(double scaleFactor);
		void setWidthHeight(int w, int h);
		void getWidthHeight(int* w, int* h);
		void rotate(double angle, SDL_Point* pivot);
		void setFlip(SDL_RendererFlip flip);
		SDL_Rect* getRect();

	private:

	protected:
		std::shared_ptr<Texture> m_texture;
		SDL_Renderer* m_renderer;
		SDL_Rect m_dstRect;
		SDL_RendererFlip m_flip;
		double angle;
		SDL_Point pivot;
	};

}