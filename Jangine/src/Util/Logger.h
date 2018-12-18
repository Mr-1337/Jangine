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

		void SetOutputStream(std::ostream& output);
		void SetLogLevel(LogLevel level);
		void SetLogTime(bool logtime);

		void Log(const std::string& message);
		void Log(const std::string& message, LogCategory category, LogLevel level);
		void LogError(const std::string& message);

		void LogErrorSDL(const std::string& message);
		void LogErrorIMG(const std::string& message);
		void LogErrorMIX(const std::string& message);
		void LogErrorTTF(const std::string& message);
		void LogErrorNET(const std::string& message);

	}
}