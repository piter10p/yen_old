#include "stdafx.h"
#include "CameraComponent.h"

using namespace yen;

CameraComponent::CameraComponent()
{
	type = "CameraComponent";
}


CameraComponent::~CameraComponent()
{
}

void CameraComponent::codeStepUpdate(ObjectAccessInterface accessInterface)
{

}

void CameraComponent::initialization(ObjectAccessInterface accessInterface)
{
	fVector position;
	position.set(0.0f, 0.0f);
	accessInterface.setPosition(position);
}

Flag CameraComponent::load()
{
	return Flag::OK;
}

