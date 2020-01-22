#pragma once
#include <Echo.h>

namespace OsuTrainer
{
	class StoryboardLayer : public Echo::Layer
	{
	private:
		Echo::Texture* background;
		Echo::VertexBuffer* vb;
		Echo::VertexLayout* vl;
		Echo::VertexArray* va;

		Echo::ShaderList* shaders;

		void TapFlashing(Echo::KeyDownEvent& e);
	public:
		StoryboardLayer();

		virtual void Update() override;
		virtual void OnEvent(Echo::Event& e) override;

		~StoryboardLayer();
	};
}