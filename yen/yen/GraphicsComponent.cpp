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
	Frame *frame = animationResource->animation.getActualFrame();
	sprite.setTexture(*frame->getTexture());

	sprite.setPosition(calculateSpritePosition(objectAccessInterface.getPosition(), objectAccessInterface.getCameraPosition()));

	RenderObject rObject;
	rObject.sprite = &sprite;

	graphicsEngine->draw(rObject);
}

void GraphicsComponent::initialization(ObjectAccessInterface objectAccessInterface)
{
	animationResource->animation.start();
}

Flag GraphicsComponent::load()
{
	return animationResource->load();
}

void GraphicsComponent::setAnimation(AnimationManipulator manipulator)
{
	animationResource = manipulator.animationResource;
}

sf::Vector2f GraphicsComponent::calculateSpritePosition(fVector objectPosition, fVector cameraPosition)
{
	objectPosition -= cameraPosition;

	return sf::Vector2f(objectPosition.getX(), objectPosition.getY());
}