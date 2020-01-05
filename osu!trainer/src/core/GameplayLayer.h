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

	/* event functions */
	float mouseX, mouseY;
	bool keyDown = false;

	// functions
	void Tapping(KeyDownEvent& e);
	void Release(KeyUpEvent& e);
	void MouseMove(MouseMoveEvent& e);
public:
	GameplayLayer();

	virtual void Update() override;
	virtual void OnEvent(Event& e) override;

	~GameplayLayer();
};