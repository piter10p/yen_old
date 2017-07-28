#include "stdafx.h"
#include "AnimationResource.h"
#include "Paths.h"

using namespace yen;

AnimationResource::AnimationResource(AnimationResourceDef def, int id)
{
	this->path = Paths::DATA_FOLDER;
	this->path += Paths::TEXTURES_FOLDER;
	this->path += def.path;
	setId(id);
}


AnimationResource::~AnimationResource()
{
}

Flag AnimationResource::load()
{
	return animation.load(path);
}

void AnimationResource::unLoad()
{
	
}

void AnimationResource::setFrameRate(unsigned int frameRate)
{
	animation.setFrameRate(frameRate);
}
