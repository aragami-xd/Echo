#pragma once

#include <EchoHeader.h>

#define LOG_init(x)\
	std::cout << "[" << __func__ << "][initialize]: " << x << std::endl;

#define LOG_message(x)\
	std::cout << "[" << __func__ << "][message]: " << x << std::endl;

#define LOG_error(x)\
	std::cout << "[" << __func__ << "][error]: " << x << std::endl;

#define LOG_warning(x)\
	std::cout << "[" << __func__ << "][warning]: " << x << std::endl;
