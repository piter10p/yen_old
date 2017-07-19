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
#include "AnimationManipulator.h"
#include "Components.h"


int main()
{
	yen::Engine engine;

	EngineConfiguration configuration;
	engine.initialize(configuration);

	yen::AnimationResourceDef animationDef;
	animationDef.path = "data\\anim";
	animationDef.frameRate = 60;
	yen::AnimationManipulator animation = engine.resourceManager->addAnimationResource(animationDef);

	yen::ObjectManipulator camera = engine.objectsManager->createObject();
	yen::CameraComponent cameraComponent;
	yen::MoveComponent moveComponent(yen::fVector(-100.0f, 0.0f));
	yen::ComponentManipulator cameraComponentManipulator;
	yen::ComponentManipulator moveComponentManipulator;
	if (engine.objectsManager->attachComponent(&cameraComponentManipulator, camera, &cameraComponent) != yen::Flag::OK)
		std::cout << "1" << std::endl;
	if (engine.objectsManager->attachComponent(&moveComponentManipulator, camera, &moveComponent) != yen::Flag::OK)
		std::cout << "2" << std::endl;


	yen::SceneManipulator scene = engine.sceneManager->createScene();
	engine.sceneManager->setSceneGravity(scene, yen::fVector(0.0f, 10.0f));


	yen::ObjectManipulator cube = engine.objectsManager->createObject();
	yen::GraphicsComponent graphicsComponent(engine.graphicsEngine);
	graphicsComponent.setAnimation(animation);
	yen::BodyDef bodyDef;
	bodyDef.type = yen::BodyType::DYNAMIC;
	bodyDef.shapeSize = yen::fVector(10.0f, 10.0f);
	yen::PhysicsComponent physicsComponent(engine.physicsEngine, bodyDef, yen::fVector(5.0f, 5.0f));
	yen::ComponentManipulator graphicsComponentManipulator;
	if (engine.objectsManager->attachComponent(&graphicsComponentManipulator, cube, &graphicsComponent) != yen::Flag::OK)
		std::cout << "3" << std::endl;
	yen::ComponentManipulator physicsComponentManipulator;
	if (engine.objectsManager->attachComponent(&physicsComponentManipulator, cube, &physicsComponent) != yen::Flag::OK)
		std::cout << "4" << std::endl;


	if(engine.sceneManager->addObjectToScene(scene, camera) != yen::Flag::OK)
		std::cout << "5" << std::endl;
	if (engine.sceneManager->addObjectToScene(scene, cube) != yen::Flag::OK)
		std::cout << "6" << std::endl;
	if(engine.sceneManager->setActiveCameraofScene(scene, camera) != yen::Flag::OK)
		std::cout << "7" << std::endl;
		
	yen::InputDef leftKeyDef;
	leftKeyDef.type = yen::InputType::KEYBOARD_KEY;
	leftKeyDef.name = "leftKey";
	leftKeyDef.key = yen::inputs::Key::Left;
	yen::InputDef rightKeyDef;
	rightKeyDef.type = yen::InputType::KEYBOARD_KEY;
	rightKeyDef.name = "rightKey";
	rightKeyDef.key = yen::inputs::Key::Right;
	yen::InputDef escapeKeyDef;
	escapeKeyDef.type = yen::InputType::KEYBOARD_KEY;
	escapeKeyDef.name = "escapeKay";
	escapeKeyDef.key = yen::inputs::Key::Escape;
	yen::InputManipulator leftKey;
	yen::InputManipulator rightKey;
	yen::InputManipulator escapeKey;
	if (engine.inputManager->createInput(&leftKey, leftKeyDef) != yen::Flag::OK)
		std::cout << "8" << std::endl;
	if (engine.inputManager->createInput(&rightKey, rightKeyDef) != yen::Flag::OK)
		std::cout << "9" << std::endl;
	if (engine.inputManager->createInput(&escapeKey, escapeKeyDef) != yen::Flag::OK)
		std::cout << "10" << std::endl;


	if(engine.sceneManager->loadScene(scene) != yen::Flag::OK)
		std::cout << "11" << std::endl;
	engine.sceneManager->initializeScene(scene);

	if (engine.run() == yen::Flag::OK)
	{
		while (engine.isRunning())
		{
			engine.step();

			if (engine.inputManager->isKeyPressed(leftKey))
				moveComponent.move(yen::fVector(2.0f, 0.0f));
			if (engine.inputManager->isKeyPressed(rightKey))
				moveComponent.move(yen::fVector(-2.0f, 0.0f));
			if (engine.inputManager->isKeyPressed(escapeKey))
				engine.stop();
		}
	}

	system("PAUSE");
	return 0;
}

