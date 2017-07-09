#include "stdafx.h"
#include "AnimationResource.h"

using namespace yen;

AnimationResource::AnimationResource(AnimationResourceDef def, int id)
{
	this->path = def.path;
	setId(id);
}


AnimationResource::~AnimationResource()
{
}

Flag AnimationResource::load()
{
	return Flag::OK;
}
