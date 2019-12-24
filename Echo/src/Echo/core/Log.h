#pragma once

#include <EchoHeader.h>

#define LOG_init(x) printf("[initialize] %s\n", x)
#define LOG_func() printf("[function] %s\n", __func__)
#define LOG_var(x) printf("[var] %s %d\n", #x, x)
#define LOG_message(x) printf("[message] %s\n", x)
#define LOG_error(x) printf("[error] %s\n", x)