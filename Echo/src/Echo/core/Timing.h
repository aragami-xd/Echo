#pragma once

#include <EchoHeader.h>
#include <Core.h>

class ECHO_DLL Timing
{
private:
	Timing() = default;

	static int startTime;
	static int prevTime;
	static int currentTime;
public:
	static inline int GetTime() 
	{
		prevTime = currentTime;
		return currentTime = (int)clock() - startTime;
	}
	static inline float GetFrameRate()
	{
		GetTime();
		return 1000 / (float)(currentTime - startTime);
	}
};