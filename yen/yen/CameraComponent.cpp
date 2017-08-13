#include "stdafx.h"
#include "CameraComponent.h"

using namespace yen;

CameraComponent::CameraComponent(GraphicsEngine *gEngine)
{
	type = "CameraComponent";
	this->gEngine = gEngine;
	active = true;
}


CameraComponent::~CameraComponent()
{
}

void CameraComponent::codeStepUpdate(ObjectAccessInterface accessInterface)
{
	if (active)
	{
		sf::Vector2f sfVector;
		sfVector.x = accessInterface.getPosition().getX();
		sfVector.y = accessInterface.getPosition().getY();

		view.setCenter(sfVector);
	}
}

void CameraComponent::initialization(ObjectAccessInterface accessInterface)
{
}

void CameraComponent::setResourcesUsed()
{
}

void CameraComponent::freezed()
{
}

void CameraComponent::unFreezed()
{
}

void CameraComponent::setSize(fVector vector)
{
	sf::Vector2f sfVector;
	sfVector.x = vector.getX();
	sfVector.y = vector.getY();

	view.setSize(sfVector);
}

void CameraComponent::setZoom(float factor)
{
	view.zoom(factor);
}

void CameraComponent::setRotation(float angle)
{
	view.setRotation(angle);
}

void CameraComponent::setViewPort(fRect rect)
{
	sf::FloatRect sfRect;
	sfRect.left = rect.getX();
	sfRect.top = rect.getY();
	sfRect.width = rect.getWidth();
	sfRect.height = rect.getHeight();

	view.setViewport(sfRect);
}

void CameraComponent::setActive(bool a)
{
	this->active = a;
}

bool CameraComponent::isActive()
{
	return active;
}

void CameraComponent::draw(std::vector <GraphicsComponent*> *gComponents)
{
	gEngine->setView(this->view);

	for (unsigned int i = 0; i < gComponents->size(); i++)
	{
		gEngine->draw((*gComponents)[i]->getRenderObject());
	}
}