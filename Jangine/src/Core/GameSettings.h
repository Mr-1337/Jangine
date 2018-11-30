#pragma once
#include "Platform.h"

//Global settings for the game

namespace Jangine
{
	namespace GameSettings
	{
		JAN_API void getDimensions(int* w, int* h);
		JAN_API void setDimensions(int w, int h);
	};
}