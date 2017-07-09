#pragma once

#include <vector>
#include "AnimationResource.h"
#include "AnimationResourceDef.h"
#include "AnimationManipulator.h"

namespace yen
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

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
