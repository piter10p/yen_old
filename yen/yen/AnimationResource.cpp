#include "stdafx.h"
#include "AnimationResource.h"

using namespace yen;

AnimationResource::AnimationResource(AnimationResourceDef def, int id)
{
	this->path = def.path;
	this->id = id;
}


AnimationResource::~AnimationResource()
{
}

bool AnimationResource::load()
{
	return true;
}
