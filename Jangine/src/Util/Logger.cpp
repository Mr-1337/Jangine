#include "Logger.h"
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_net.h>

namespace Jangine
{
	namespace Logger
	{

		namespace
		{
			std::ostream* output_ = nullptr;
			LogLevel logLevel = LEVEL_TRACE;
		}

		void SetOutputStream(std::ostream& output)
		{
			output_ = &output;
		}

		void SetLogLevel(LogLevel level)
		{
			logLevel = level;
		}

		void Log(const std::string& message)
		{
			Log(message, LOG_DEBUG, LEVEL_CRITICAL);
		}

		void LogError(const std::string& message)
		{
			Log(message, LOG_ERROR, LEVEL_CRITICAL);
		}

		void Log(const std::string& message, LogCategory category, LogLevel level)
		{
			if (output_ != nullptr)
			{
				auto &o = *output_;

				if (level >= logLevel)
				{
					switch (category)
					{
					case LOG_INFO:
						o << "[INFO] " << message << std::endl;
						break;
					case LOG_DEBUG:
						o << "[DEBUG] " << message << std::endl;
						break;
					case LOG_ERROR:
						o << "[ERROR] " << message << std::endl;
						break;
					default:
						o << "[Unknown Category???] " << message << std::endl;
					}
				}
			}
			else
			{
				throw std::runtime_error("Logger ostream pointer was null! Make sure you set it before trying to log!");
			}
		}
		void LogErrorSDL(const std::string & message)
		{
			Log(message + ": " + SDL_GetError(), LOG_ERROR, LEVEL_CRITICAL);
		}
		void LogErrorIMG(const std::string & message)
		{
			Log(message + ": " + IMG_GetError(), LOG_ERROR, LEVEL_CRITICAL);
		}
		void LogErrorMIX(const std::string & message)
		{
			Log(message + ": " + Mix_GetError(), LOG_ERROR, LEVEL_CRITICAL);
		}
		void LogErrorTTF(const std::string & message)
		{
			Log(message + ": " + TTF_GetError(), LOG_ERROR, LEVEL_CRITICAL);
		}
		void LogErrorNET(const std::string & message)
		{
			Log(message + ": " + SDLNet_GetError(), LOG_ERROR, LEVEL_CRITICAL);
		}
	}
}