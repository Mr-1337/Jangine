#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include "../Core/Globals.h"
#include "Texture.h"

#pragma once

namespace Jangine
{

	class TextureManager
	{
	public:
		TextureManager() = delete;
		~TextureManager() = delete;

		static Texture* GetTexture(const std::string& textureName);

	private:
		static std::map<std::string, Texture*> m_textureAtlas;
		static SDL_Renderer* m_renderer;
	};

}

