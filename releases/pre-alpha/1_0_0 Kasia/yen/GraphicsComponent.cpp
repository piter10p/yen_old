#include "stdafx.h"
#include "GraphicsComponent.h"
#include "RenderObject.h"

using namespace yen;

GraphicsComponent::GraphicsComponent(GraphicsEngine *engine, GraphicsComponentContent content)
{
	graphicsEngine = engine;
	this->graphicsComponentContent = content;
	type = "GraphicsComponent";
}


GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::codeStepUpdate(ObjectAccessInterface objectAccessInterface)
{
	if (graphicsComponentContent == GraphicsComponentContent::SPRITE)
	{
		Frame *frame = animationManager.getActualFrame();
		sprite.setTexture(*frame->getTexture());

		sprite.setPosition(fVector2sfVector(objectAccessInterface.getPosition()));
	}
	else if (graphicsComponentContent == GraphicsComponentContent::TEXT)
	{
		text.setPosition(fVector2sfVector(objectAccessInterface.getPosition()));
	}
}

void GraphicsComponent::initialization(ObjectAccessInterface objectAccessInterface)
{
	if (graphicsComponentContent == GraphicsComponentContent::SPRITE)
		animationManager.start();
	else if (graphicsComponentContent == GraphicsComponentContent::TEXT)
	{
		text.setFont(fontResource->getFont());
		text.setString(stringResource->getString(stringName));
	}
}

void GraphicsComponent::setResourcesUsed()
{
	if(graphicsComponentContent == GraphicsComponentContent::SPRITE)
		animationManager.setResourcesUsed();
	else if (graphicsComponentContent == GraphicsComponentContent::TEXT)
	{
		fontResource->used();
		stringResource->used();
	}
}

void GraphicsComponent::freezed()
{
}

void GraphicsComponent::unFreezed()
{
}

void GraphicsComponent::setActualAnimation(AnimationManipulator manipulator)
{
	animationManager.setActualAnimation(manipulator);
}

void GraphicsComponent::addAnimation(AnimationManipulator manipulator)
{
	animationManager.addAnimation(manipulator);
}

void GraphicsComponent::removeAnimation(AnimationManipulator manipulator)
{
	animationManager.removeAnimation(manipulator);
}

void GraphicsComponent::setString(StringManipulator manipulator, std::string stringName)
{
	stringResource = manipulator.resource;
	this->stringName = stringName;
}

void GraphicsComponent::setFontResource(FontManipulator manipulator)
{
	fontResource = manipulator.resource;
}

void GraphicsComponent::setTextAttributes(TextAttributes attributes)
{
	text.setCharacterSize(attributes.charactersSize);
	text.setFillColor(yenColorToSfColor(attributes.textColor));
	//text.setFillColor(sf::Color::Black);
}

sf::Vector2f GraphicsComponent::fVector2sfVector(fVector objectPosition)
{
	return sf::Vector2f(objectPosition.getX(), objectPosition.getY());
}

sf::Color GraphicsComponent::yenColorToSfColor(Color in)
{
	sf::Color out;

	out.r = (sf::Uint8)in.getR();
	out.g = (sf::Uint8)in.getG();
	out.b = (sf::Uint8)in.getB();
	out.a = (sf::Uint8)in.getA();


	return out;
}

RenderObject GraphicsComponent::getRenderObject()
{
	RenderObject rObject;

	if (graphicsComponentContent == GraphicsComponentContent::SPRITE)
	{
		rObject.drawable = &sprite;
	}
	else if (graphicsComponentContent == GraphicsComponentContent::TEXT)
	{
		rObject.drawable = &text;
	}

	return rObject;
}