#pragma once
#include "Resource.h"
#include <string>
#include "AnimationResourceDef.h"

namespace yen
{
	class AnimationResource :public Resource
	{
	public:
		AnimationResource(AnimationResourceDef, int);
		~AnimationResource();

	protected:
		Flag load();

		std::string path;
	};
}
