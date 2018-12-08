#pragma once
#include "ButtonBase.h"
#include <SDL_mixer.h>

namespace Jangine
{

	class Slider :
		public ButtonBase
	{
	public:
		Slider();
		void onHover() override;
		void update() override;
		void draw() override;
		void setY(int y) override;
		void setX(int x) override;
		~Slider();
	private:
		SDL_Rect wedge;
	};

}