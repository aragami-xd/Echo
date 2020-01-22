#pragma once

/* set export or import dll mode */
#ifdef ECHO_GEN_WINDOWS
#ifdef ECHO_GEN_BUILD
#define ECHO_GEN_DLL __declspec(dllexport)
#else
#define ECHO_GEN_DLL __declspec(dllimport)
#endif
#endif
