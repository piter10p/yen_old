#pragma once
#include "Component.h"
#include "Time.h"

namespace yen
{
	class MoveComponent : public Component
	{
	public:
		MoveComponent(fVector position);
		~MoveComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		Flag load();
		void unLoad();

		void move(fVector);
		void setPosition(fVector);

	private:
		fVector position;
		time::LoopTimer timer;
		const float elapseTime = 0.001f;
	};
}
