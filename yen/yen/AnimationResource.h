#pragma once
#include "Resource.h"
#include <string>
#include "AnimationResourceDef.h"
#include "Animation.h"

namespace yen
{
	class AnimationResource :public Resource
	{
	public:
		AnimationResource(AnimationResourceDef, int);
		~AnimationResource();

		Flag load();
		void unLoad();
		void setFrameRate(unsigned int);

		friend class GraphicsComponent;
	protected:
		Animation animation;

	private:
		std::string path;
	};
}
