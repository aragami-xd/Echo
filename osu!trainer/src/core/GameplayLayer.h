#pragma once

#include <Echo/core/ShaderList.h>
#include <Echo/components/Parser.h>
#include <Echo.h>

class GameplayLayer : public Layer
{
private:
	// shaders
	ShaderList* shaders;

	// parser
	Parser* parser;

	// object component vector
	std::vector<ObjectComponent*> object;
	int objectIterate = 0;
public:
	GameplayLayer();

	virtual void Update() override;
	virtual void OnEvent(const Event& e) override;

	~GameplayLayer();
};