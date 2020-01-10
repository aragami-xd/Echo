#pragma once

#include <nlohmann/json.hpp>
#include <EchoHeader.h>

using json = nlohmann::json;

const json settings = json::parse(
	std::ifstream("C:/Users/Rogue/source/repos/Echo/Echo/src/Settings.json")
);