#include "TextureManager.h"
#include "../Util/Logger.h"

namespace Jangine
{

	SDL_Renderer* TextureManager::m_renderer = SDL_GetRenderer(Globals::getWindow());
	std::map<std::string, Texture*> TextureManager::m_textureAtlas;

	Texture* TextureManager::GetTexture(const std::string& textureName)
	{
		if (m_textureAtlas.find(textureName) == m_textureAtlas.end())
		{
			Logger::Log(textureName + " was not found in the atlas. Attempting to load it from disk.", Logger::LOG_INFO, Logger::LEVEL_TRACE);
			m_textureAtlas[textureName] = new Texture(textureName);
		}
		return m_textureAtlas[textureName];
	}

}