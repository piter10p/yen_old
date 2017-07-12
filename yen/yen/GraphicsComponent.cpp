#include "stdafx.h"
#include "GraphicsComponent.h"
#include "RenderObject.h"

using namespace yen;

GraphicsComponent::GraphicsComponent(GraphicsEngine *engine)
{
	graphicsEngine = engine;
}


GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::codeStepUpdate(ObjectAccessInterface objectAccessInterface)
{
	Frame *frame = animationResource->animation.getActualFrame();
	sprite.setTexture(*frame->getTexture());

	sf::Vector2f position;
	position.x = (objectAccessInterface.getPosition().getX());
	position.y = (objectAccessInterface.getPosition().getY());
	sprite.setPosition(position);

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