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

void GraphicsComponent::load()
{
	animationManager.load();
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

sf::Vector2f GraphicsComponent::calculateSpritePosition(fVector objectPosition, fVector cameraPosition)
{
	objectPosition -= cameraPosition;

	return sf::Vector2f(objectPosition.getX(), objectPosition.getY());
}

void GraphicsComponent::unLoad()
{
	animationManager.unLoad();
}