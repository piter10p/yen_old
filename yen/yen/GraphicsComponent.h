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
		void unLoad();

		void setAnimation(AnimationManipulator);

	private:
		GraphicsEngine *graphicsEngine;
		AnimationResource *animationResource;
		sf::Sprite sprite;

		sf::Vector2f calculateSpritePosition(fVector objectPosition, fVector cameraPosition);
	};
}
