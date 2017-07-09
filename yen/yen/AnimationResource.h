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

		Flag load();

	private:
		std::string path;
	};
}
