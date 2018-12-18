#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include "../Core/Globals.h"
#include "Texture.h"

#pragma once

namespace Jangine
{
	/*
		The TextureManager is a static utility that contains an std::map of Texture objects.
		Sprites can load their textures from the TextureManager to avoid unessescarily loading
		multiple instances of the same image data. If GetTexture cannot find the specified
		image already in the texture atlas, it will attempt to load it from disk.
	*/
	class TextureManager
	{
	public:
		TextureManager() = delete;
		~TextureManager() = delete;

		static std::shared_ptr<Texture> GetTexture(const std::string& textureName);
		static void FlushAtlas();

	private:
		static std::unordered_map<std::string, std::shared_ptr<Texture>> m_textureAtlas;
		static SDL_Renderer* m_renderer;
	};

}

