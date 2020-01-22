#pragma once

#include <Echo.h>

namespace OsuTrainer
{
	class GameplayLayer : public Echo::Layer
	{
	private:
		// shaders
		Echo::ShaderList* shaders;

		// parser
		Echo::Parser* parser;

		// scoring
		Echo::Scoring* scoring;

		// object component vector
		std::vector<Echo::ObjectComponent*> object;
		int objectIterate = 0;

		/* event functions */
		float mouseX, mouseY;
		bool keyDown = false;

		// functions
		void Tapping(Echo::KeyDownEvent& e);
		void Release(Echo::KeyUpEvent& e);
		void MouseMove(Echo::MouseMoveEvent& e);
	public:
		GameplayLayer();

		virtual void Update() override;
		virtual void OnEvent(Echo::Event& e) override;

		~GameplayLayer();
	};
}