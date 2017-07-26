#include "stdafx.h"
#include "GraphicsComponent.h"
#include "RenderObject.h"

using namespace yen;

GraphicsComponent::GraphicsComponent(GraphicsEngine *engine)
{
	graphicsEngine = engine;
	type = "GraphicsComponent";
}


GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::codeStepUpdate(ObjectAccessInterface objectAccessInterface)
{
	Frame *frame = animationManager.getActualFrame();
	sprite.setTexture(*frame->getTexture());

	sprite.setPosition(calculateSpritePosition(objectAccessInterface.getPosition(), objectAccessInterface.getCameraPosition()));

	RenderObject rObject;
	rObject.sprite = &sprite;

	graphicsEngine->draw(rObject);
}

void GraphicsComponent::initialization(ObjectAccessInterface objectAccessInterface)
{
	animationManager.start();
}

Flag GraphicsComponent::load()
{
	return animationManager.load();
}

Flag GraphicsComponent::setActualAnimation(AnimationManipulator manipulator)
{
	return animationManager.setActualAnimation(manipulator);
}

Flag GraphicsComponent::addAnimation(AnimationManipulator manipulator)
{
	return animationManager.addAnimation(manipulator);
}

Flag GraphicsComponent::removeAnimation(AnimationManipulator manipulator)
{
	return animationManager.removeAnimation(manipulator);
}

sf::Vector2f GraphicsComponent::calculateSpritePosition(fVector objectPosition, fVector cameraPosition)
{
	objectPosition -= cameraPosition;

	return sf::Vector2f(objectPosition.getX(), objectPosition.getY());
}

void GraphicsComponent::unLoad()
{
	animationManager.unLoad();
}