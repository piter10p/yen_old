#pragma once
#include "Component.h"
#include "GraphicsComponent.h"
#include <SFML\Graphics.hpp>
#include "GraphicsEngine.h"
#include <vector>

namespace yen
{
	class CameraComponent : public Component
	{
	public:
		CameraComponent(GraphicsEngine*);
		~CameraComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		void setResourcesUsed();

		void freezed();
		void unFreezed();

		void setSize(fVector);
		void setZoom(float);
		void setRotation(float angle);
		void setViewPort(fRect);

		void setActive(bool);
		bool isActive();

		void draw(std::vector <GraphicsComponent*>*);

	private:
		sf::View view;
		GraphicsEngine *gEngine;
		bool active;
	};
}
