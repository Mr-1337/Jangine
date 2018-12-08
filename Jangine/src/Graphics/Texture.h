#pragma once

#include <string>
#include <SDL_render.h>

namespace Jangine
{

	class Texture
	{
		int m_width, m_height;
		SDL_Texture* m_rawTexture;
		SDL_Renderer* m_renderer;
	public:
		Texture(const std::string& path);
		Texture(SDL_Surface* surface);
		~Texture();

		inline SDL_Texture* GetRaw() { return m_rawTexture; }

		inline int GetWidth() { return m_width; }
		inline int GetHeight() { return m_height; }
	};

}
