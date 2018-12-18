#pragma once

#include<sstream>
#include<chrono>
#include<time.h>
#include<iomanip>

class DateTime
{
public:
	static std::string GetDateTime()
	{
		auto now = std::chrono::system_clock::now();
		auto now_t = std::chrono::system_clock::to_time_t(now);
		tm tm;
		localtime_s(&tm, &now_t);
		std::stringstream time;
		time << std::put_time(&tm, "%F, %T");
		return time.str();
	}
};