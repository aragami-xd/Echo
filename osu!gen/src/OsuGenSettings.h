#pragma once

#include <EchoGenHeader.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace OsuGen
{
	const json settings = json::parse(std::ifstream(std::filesystem::current_path().string() + "/src/OsuGenSettings.h"));
}