#pragma once
#include "Component.h"
#include "GraphicsEngine.h"
#include "SFML\Graphics.hpp"
#include "AnimationManager.h"
#include "StringManipulator.h"
#include "FontManipulator.h"
#include "Color.h"

namespace yen
{
	enum GraphicsComponentContent
	{
		SPRITE,
		TEXT
	};

	struct TextAttributes
	{
		unsigned int charactersSize;
		Color textColor;
	};

	class GraphicsComponent :public Component
	{
	public:
		GraphicsComponent(GraphicsEngine*, GraphicsComponentContent content = GraphicsComponentContent::SPRITE);
		~GraphicsComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		void load();
		void unLoad();

		void setActualAnimation(AnimationManipulator);
		void addAnimation(AnimationManipulator);
		void removeAnimation(AnimationManipulator);

		void setString(StringManipulator, std::string stringName);
		void setFontResource(FontManipulator);
		void setTextAttributes(TextAttributes);

	private:
		GraphicsEngine *graphicsEngine;
		AnimationManager animationManager;
		sf::Sprite sprite;
		sf::Text text;

		FontResource *fontResource;
		StringResource *stringResource;
		std::string stringName;

		GraphicsComponentContent graphicsComponentContent;
		

		sf::Vector2f calculateSpritePosition(fVector objectPosition, fVector cameraPosition);
		sf::Color yenColorToSfColor(Color);
	};
}
