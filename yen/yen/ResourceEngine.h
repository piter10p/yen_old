#pragma once

#include <vector>
#include "AnimationResource.h"
#include "AnimationResourceDef.h"
#include "AnimationManipulator.h"

namespace yen
{
	class ResourceEngine
	{
	public:
		ResourceEngine();
		~ResourceEngine();

		AnimationManipulator addAnimationResource(AnimationResourceDef);
		Flag removeAnimationResource(AnimationManipulator);

	protected:
		std::vector <AnimationResource*> animationResources;

	private:
		int idCounter;

		int getId();

		bool isIdSame(ResourceManipulator*, Resource*);

		void clearAllResources();
	};
}
