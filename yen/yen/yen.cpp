// yen.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Engine.h"
#include "Flag.h"
#include "Animation.h"
#include "AnimationResourceDef.h"
#include "SceneManipulator.h"
#include "ObjectManipulator.h"
#include "GraphicsComponent.h"
#include "AnimationManipulator.h"
#include "ComponentManipulator.h"
#include "CameraComponent.h"


int main()
{
	class MoveComponent : public yen::Component
	{
	public:
		MoveComponent()
		{
			type = "MoveComponent";
		}

		void codeStepUpdate(yen::ObjectAccessInterface) {}
		void initialization(yen::ObjectAccessInterface i)
		{
			i.setPosition(yen::fVector(-50.0f, -100.0f));
		}

		yen::Flag load() {return yen::Flag::OK;}
	};

	yen::Engine engine;

	EngineConfiguration configuration;
	engine.initialize(configuration);

	yen::AnimationResourceDef animationDef;
	animationDef.path = "data\\anim";
	animationDef.frameRate = 60;
	yen::AnimationManipulator animation = engine.resourceManager->addAnimationResource(animationDef);

	yen::ObjectManipulator camera = engine.objectsManager->createObject();
	yen::CameraComponent cameraComponent;
	MoveComponent moveComponent;
	yen::ComponentManipulator cameraComponentManipulator;
	yen::ComponentManipulator moveComponentManipulator;
	if (engine.objectsManager->attachComponent(&cameraComponentManipulator, camera, &cameraComponent) != yen::Flag::OK)
		std::cout << "1" << std::endl;
	if (engine.objectsManager->attachComponent(&moveComponentManipulator, camera, &moveComponent) != yen::Flag::OK)
		std::cout << "2" << std::endl;


	yen::ObjectManipulator cube = engine.objectsManager->createObject();
	yen::GraphicsComponent graphicsComponent(engine.graphicsEngine);
	graphicsComponent.setAnimation(animation);
	yen::ComponentManipulator graphicsComponentManipulator;
	if (engine.objectsManager->attachComponent(&graphicsComponentManipulator, cube, &graphicsComponent) != yen::Flag::OK)
		std::cout << "3" << std::endl;


	yen::SceneManipulator scene = engine.sceneManager->createScene();
	if(engine.sceneManager->addObjectToScene(scene, camera) != yen::Flag::OK)
		std::cout << "4" << std::endl;
	if (engine.sceneManager->addObjectToScene(scene, cube) != yen::Flag::OK)
		std::cout << "5" << std::endl;
	if(engine.sceneManager->setActiveCameraofScene(scene, camera) != yen::Flag::OK)
		std::cout << "6" << std::endl;
		
	

	if(engine.sceneManager->loadScene(scene) != yen::Flag::OK)
		std::cout << "7" << std::endl;
	engine.sceneManager->initializeScene(scene);

	if (engine.run() == yen::Flag::OK)
	{
		while (engine.isRunning())
		{
			engine.step();
		}
	}

	system("PAUSE");
	return 0;
}

