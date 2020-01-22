#pragma once

#include <nlohmann/json.hpp>
#include <EchoHeader.h>

using json = nlohmann::json;

namespace Echo
{
	const json settings = json::parse(
#ifdef ECHO_DEBUG
		std::ifstream(std::filesystem::current_path().string() + "/../Echo/src/Settings.json")
#else
		std::ifstream(std::filesystem::current_path().string() + "/Settings.json")
#endif
	);
}