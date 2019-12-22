#pragma once

/* set export or import dll mode */
#ifdef ECHO_WINDOWS
	#ifdef ECHO_BUILD
		#define ECHO_API __declspec(dllexport)
	#else
		#define ECHO_API __declspec(dllimport)
	#endif // ECHO_BUILD
#endif // ECHO_WINDOWS