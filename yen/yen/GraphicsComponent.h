#pragma once
#include "Component.h"
#include "GraphicsEngine.h"

namespace yen
{
	class GraphicsComponent :public Component
	{
	public:
		GraphicsComponent(GraphicsEngine*);
		~GraphicsComponent();

		void codeStepUpdate();

	protected:
		const std::string type = "GraphicsComponent";
	};
}
