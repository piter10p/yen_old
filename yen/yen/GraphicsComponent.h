#pragma once
#include "Component.h"
#include "GraphicsEngine.h"
#include "SFML\Graphics.hpp"
#include "AnimationManager.h"

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
		void unLoad();

		Flag setActualAnimation(AnimationManipulator);
		Flag addAnimation(AnimationManipulator);
		Flag removeAnimation(AnimationManipulator);

	private:
		GraphicsEngine *graphicsEngine;
		AnimationManager animationManager;
		sf::Sprite sprite;

		sf::Vector2f calculateSpritePosition(fVector objectPosition, fVector cameraPosition);
	};
}
