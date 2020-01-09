#pragma once

#include <EchoHeader.h>
#include <Core.h>

class ECHO_DLL Timing
{
private:
	Timing() = default;
	static std::chrono::steady_clock::time_point startTime;
	static int offset;
public:
	static inline void StartProgram()
	{
		startTime = std::chrono::steady_clock::now();
	}

	static inline int GetTime()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::steady_clock::now() - startTime).count() - offset;
	}
};