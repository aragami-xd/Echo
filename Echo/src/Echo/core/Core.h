#pragma once

/* set export or import dll mode */
#ifdef ECHO_BUILD
#define ECHO_DLL __declspec(dllexport)
#else
#define ECHO_DLL __declspec(dllimport)
#endif
