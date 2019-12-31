#pragma once

#include <EchoHeader.h>

#define LOG_init(x)\
	printf("[%s][initialize] %s\n", __func__, x)

#define LOG_var(x)\
	printf("[%s][var] %s %d\n", __func__, #x, x)

#define LOG_message(x)\
	printf("[%s][message] %s\n", __func__, x)

#define LOG_error(x)\
	printf("[%s][error] %s\n", __func__, x)

#define LOG_warning(x)\
	printf("[%s][warning] %s\n",__func__, x)
