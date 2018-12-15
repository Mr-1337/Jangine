#include "GameSettings.h"  

namespace Jangine
{
	namespace GameSettings
	{
		namespace
		{
			int width;
			int height;
		}

		void getDimensions(int* w, int* h)
		{
			*w = width;
			*h = height;
		}

		void setDimensions(int w, int h)
		{
			width = w;
			height = h;
		}
	}
}