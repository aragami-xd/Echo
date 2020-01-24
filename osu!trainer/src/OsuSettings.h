#pragma once

#include <nlohmann/json.hpp>
#include <EchoHeader.h>

using json = nlohmann::json;

namespace OsuTrainer
{
	const json settings = json::parse(std::ifstream(
		std::filesystem::current_path().string() + "/src/OsuSettings.json")
	);
}