#pragma once

#include "Manager.h"
#include "AnimationResource.h"
#include "AnimationResourceDef.h"
#include "AnimationManipulator.h"
#include "IdSetter.h"

namespace yen
{
	class ResourceManager: public Manager, public IdSetter
	{
	public:
		ResourceManager();
		~ResourceManager();

		AnimationManipulator addAnimationResource(AnimationResourceDef);
		Flag removeAnimationResource(AnimationManipulator);

		bool test();

	protected:
		std::vector <AnimationResource> animationResources;

	private:
		bool isIdSame(ResourceManipulator*, Resource*);
		void clearAllResources();
		int getIndexOfAnimationResourcesListObject(int id);
	};
}
