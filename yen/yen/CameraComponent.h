#pragma once
#include "Component.h"

namespace yen
{
	class CameraComponent : public Component
	{
	public:
		CameraComponent();
		~CameraComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		void setResourcesUsed();

		void freezed();
		void unFreezed();
	};
}
