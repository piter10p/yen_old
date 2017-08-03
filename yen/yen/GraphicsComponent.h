#pragma once
#include "Component.h"
#include "GraphicsEngine.h"
#include "SFML\Graphics.hpp"
#include "AnimationManager.h"
#include "StringManipulator.h"

namespace yen
{
	class GraphicsComponent :public Component
	{
	public:
		GraphicsComponent(GraphicsEngine*);
		~GraphicsComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		void load();
		void unLoad();

		void setActualAnimation(AnimationManipulator);
		void addAnimation(AnimationManipulator);
		void removeAnimation(AnimationManipulator);

	private:
		GraphicsEngine *graphicsEngine;
		AnimationManager animationManager;
		sf::Sprite sprite;

		sf::Vector2f calculateSpritePosition(fVector objectPosition, fVector cameraPosition);
	};
}
