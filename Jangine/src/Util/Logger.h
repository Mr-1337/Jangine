#pragma once

#include "../Core/Platform.h"
#include <iostream>
#include <sstream>

namespace Jangine
{
	namespace Logger
	{
		enum LogCategory
		{
			LOG_INFO,
			LOG_DEBUG,
			LOG_ERROR
		};
		enum LogLevel
		{
			LEVEL_TRACE,
			LEVEL_DEBUG,
			LEVEL_WARNING,
			LEVEL_CRITICAL
		};

		JAN_API void SetOutputStream(std::ostream& output);
		JAN_API void SetLogLevel(LogLevel level);

		JAN_API void Log(const std::string& message);
		JAN_API void Log(const std::string& message, LogCategory category, LogLevel level);
		JAN_API void LogError(const std::string& message);

		JAN_API void LogErrorSDL(const std::string& message);
		JAN_API void LogErrorIMG(const std::string& message);
		JAN_API void LogErrorMIX(const std::string& message);
		JAN_API void LogErrorTTF(const std::string& message);
		JAN_API void LogErrorNET(const std::string& message);

	}
}