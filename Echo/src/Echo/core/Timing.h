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
	static inline void Refresh()
	{
		prevTime = currentTime;
		currentTime = (int)clock() - startTime;
	}
	static inline int GetTime() 
	{
		return currentTime; 
	}
	static inline float GetFrameRate()
	{
		return 1000 / (float)(currentTime - startTime);
	}
};