#include "Texture.h"
#include <SDL_image.h>
#include "../Util/Logger.h"
#include "../Core/Globals.h"

namespace Jangine
{

	Texture::Texture(const std::string& path) :
		m_renderer(SDL_GetRenderer(Globals::getWindow())), m_width(0), m_height(0)
	{
		SDL_Surface* tempSurface;
		tempSurface = IMG_Load(path.c_str());
		if (tempSurface == nullptr)
		{
			Logger::LogErrorIMG("Error loading image");
		}
		else
		{
			if (m_renderer == nullptr)
			{
				Logger::LogError("Renderer is null");
			}
			else
			{
				m_rawTexture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
				m_width = tempSurface->w;
				m_height = tempSurface->h;
				std::stringstream s;
				s << "Loaded texture " << path << " with dimensions of " << m_width << " x " << m_height;
				using namespace Logger;
				Log(s.str(), LOG_INFO, LEVEL_TRACE);
			}
		}
		SDL_FreeSurface(tempSurface);
	}

	Texture::Texture(SDL_Surface* surface) :
		m_renderer(SDL_GetRenderer(Globals::getWindow())), m_width(0), m_height(0)
	{
		if (surface == nullptr)
		{
			Logger::LogError("Surface was NULL");
		}
		else
		{
			m_rawTexture = SDL_CreateTextureFromSurface(m_renderer, surface);
			m_width = surface->w;
			m_height = surface->h;
			std::stringstream s;
			s << "Loaded texture with dimensions of " << m_width << " x " << m_height << std::endl;
			using namespace Logger;
			Log(s.str(), LOG_INFO, LEVEL_TRACE);
		}
	}


	Texture::~Texture()
	{
		SDL_DestroyTexture(m_rawTexture);
	}

}
