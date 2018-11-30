#pragma once

#ifdef JAN_BUILD_DLL
	#define JAN_API __declspec(dllexport)
#else
	#define JAN_API __declspec(dllimport)
#endif