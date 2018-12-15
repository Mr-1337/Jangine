#include "Sprite.h"
#include "../Core/GameSettings.h"
#include "../Util/Logger.h"

namespace Jangine
{

	Sprite::Sprite()
		:m_renderer(SDL_GetRenderer(Globals::getWindow())), m_flip(SDL_FLIP_NONE), angle(0)
	{
		if (m_renderer != nullptr)
		{
			Logger::Log("Sprite Created!", Jangine::Logger::LOG_INFO, Jangine::Logger::LEVEL_TRACE);
		}
		else
		{
			Logger::LogError("Renderer is null :( for this sprite");
		}
	}

	Sprite::~Sprite()
	{
		Logger::Log("Sprite Destroyed!", Jangine::Logger::LOG_INFO, Jangine::Logger::LEVEL_TRACE);
	}

	void Sprite::setFlip(SDL_RendererFlip flip)
	{
		m_flip = flip;
	}

	void Sprite::setX(int x)
	{
		m_dstRect.x = x;
	}

	void Sprite::setY(int y)
	{
		m_dstRect.y = y;
	}

	void Sprite::setWidthHeight(int w, int h)
	{
		m_dstRect.w = w;
		m_dstRect.h = h;
	}

	void Sprite::getWidthHeight(int* w, int* h)
	{
		*w = m_dstRect.w;
		*h = m_dstRect.h;
	}

	SDL_Rect* Sprite::getRect()
	{
		return &m_dstRect;
	}

	void Sprite::Scale(double scaleFactor)
	{
		int tw, th;
		getWidthHeight(&tw, &th);
		setWidthHeight((double)tw * scaleFactor, (double)th * scaleFactor);
	}

	void Sprite::draw()
	{
		if (m_renderer != nullptr && m_texture != nullptr)
		{
			SDL_RenderCopyEx(m_renderer, m_texture->GetRaw(), nullptr, &m_dstRect, angle, &pivot, m_flip);
		}
		else
		{
			Logger::LogError("Renderer or texture was null :(");
		}
	}

	void Sprite::setAlpha(int alpha)
	{
		if (alpha < 0)
			alpha = 0;
		if (alpha > 255)
			alpha = 255;
		if (SDL_SetTextureAlphaMod(m_texture->GetRaw(), alpha) != 0)
			std::cout << SDL_GetError() << std::endl;
	}

	void Sprite::draw(SDL_Rect& clip)
	{
		if (m_renderer != nullptr && m_texture != nullptr)
		{
			m_dstRect.w = clip.w;
			m_dstRect.h = clip.h;
			SDL_RenderCopy(m_renderer, m_texture->GetRaw(), &clip, &m_dstRect);
		}
		else
		{
			Logger::LogError("Renderer, bounding rect, or texture are null");
		}
	}


	void Sprite::rotate(double angle, SDL_Point* pivot)
	{
		if (pivot != nullptr)
		{
			this->pivot = *pivot;
		}
		this->angle = angle;
	}

	void Sprite::load(const std::string& path)
	{

		m_texture = TextureManager::GetTexture(path);

		m_dstRect.x = 0;
		m_dstRect.y = 0;
		m_dstRect.w = m_texture->GetWidth();
		m_dstRect.h = m_texture->GetHeight();
		pivot.x = m_dstRect.x + m_dstRect.w / 2;
		pivot.y = m_dstRect.y + m_dstRect.h / 2;
		using namespace Logger;
		Log("Loaded Sprite", LOG_INFO, LEVEL_TRACE);

	}

}