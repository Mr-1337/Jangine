#include "AnimatedSprite.h"
#include "TextureManager.h"

namespace Jangine
{

	AnimatedSprite::AnimatedSprite(SDL_Rect rect)
		:frame(0), frameTime(1000), drawRegion(rect)
	{

	}


	AnimatedSprite::~AnimatedSprite()
	{
	}


	void AnimatedSprite::setFrameTime(int time)
	{
		frameTime = time;
	}


	void AnimatedSprite::load(std::string path)
	{

		m_texture = TextureManager::GetTexture(path);
		m_dstRect = drawRegion;

		timer.start();
	}

	void AnimatedSprite::draw()
	{
		if (timer.getTicks() > frameTime)
		{
			frame++;
			timer.restart();
		}
		if (frame > 6)
			frame = 0;
		drawRegion.x = drawRegion.w * frame;
		SDL_RenderCopyEx(m_renderer, m_texture->GetRaw(), &drawRegion, &m_dstRect, angle, &pivot, m_flip);
	}

}