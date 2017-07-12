#pragma once
#include "Component.h"
#include "GraphicsEngine.h"
#include "SFML\Graphics.hpp"
#include "AnimationManipulator.h"
#include "Animation.h"

namespace yen
{
	class GraphicsComponent :public Component
	{
	public:
		GraphicsComponent(GraphicsEngine*);
		~GraphicsComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		Flag load();

		void setAnimation(AnimationManipulator);

	protected:
		const std::string type = "GraphicsComponent";

	private:
		GraphicsEngine *graphicsEngine;
		AnimationResource *animationResource;
		sf::Sprite sprite;
	};
}
