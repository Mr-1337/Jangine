#include "TextureManager.h"
#include "../Util/Logger.h"

namespace Jangine
{

	SDL_Renderer* TextureManager::m_renderer = Globals::getRenderer();
	std::unordered_map<std::string, std::shared_ptr<Texture>> TextureManager::m_textureAtlas;

	std::shared_ptr<Texture> TextureManager::GetTexture(const std::string& textureName)
	{
		if (m_textureAtlas.find(textureName) == m_textureAtlas.end())
		{
			Logger::Log(textureName + " was not found in the atlas. Attempting to load it from disk.", Logger::LOG_INFO, Logger::LEVEL_TRACE);
			m_textureAtlas[textureName] = std::make_shared<Texture>(textureName);
		}
		return m_textureAtlas[textureName];
	}

	void TextureManager::FlushAtlas()
	{
		for(auto& t : m_textureAtlas)
		{
			if (t.second.use_count() == 1)
				;
		}
	}

}