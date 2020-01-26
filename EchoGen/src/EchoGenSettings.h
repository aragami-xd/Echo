#pragma once

#include <EchoGenHeader.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace EchoGen
{
	const json settings = json::parse(std::ifstream(
#ifdef ECHO_GEN_DEBUG
		std::filesystem::current_path().string() + "/../EchoGen/src/EchoGenSettings.h"
#else
		std::filesystem::current_path().string() + "EchoGenSettings.h"
#endif
	));
}