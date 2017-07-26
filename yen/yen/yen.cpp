// yen.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "yen.h"


int main()
{
	yen::Engine engine;

	EngineConfiguration configuration;
	engine.initialize(configuration);

	yen::AnimationResourceDef animationDef;
	animationDef.path = "I:\\Backup\\Pietras\\data\\anim";
	animationDef.frameRate = 60;
	yen::AnimationManipulator animation = engine.resourceManager->addAnimationResource(animationDef);
	animationDef.path += "2";
	animationDef.frameRate = 0;
	yen::AnimationManipulator animation2 = engine.resourceManager->addAnimationResource(animationDef);

	yen::ObjectManipulator camera = engine.objectsManager->createObject(yen::fVector(-100.0f, 0.0f));
	yen::CameraComponent cameraComponent;
	yen::MoveComponent moveComponent(yen::fVector(-100.0f, 0.0f));
	yen::ComponentManipulator cameraComponentManipulator;
	yen::ComponentManipulator moveComponentManipulator;
	engine.objectsManager->attachComponent(&cameraComponentManipulator, camera, &cameraComponent);
	engine.objectsManager->attachComponent(&moveComponentManipulator, camera, &moveComponent);


	yen::SceneManipulator scene = engine.sceneManager->createScene();
	engine.sceneManager->setSceneGravity(scene, yen::fVector(0.0f, 10.0f));


	yen::ObjectManipulator cube = engine.objectsManager->createObject(yen::fVector(0.0f, 0.0f));
	engine.objectsManager->setLoadDistance(cube, 200.0f);
	yen::GraphicsComponent graphicsComponent(engine.graphicsEngine);
	graphicsComponent.addAnimation(animation);
	graphicsComponent.addAnimation(animation2);
	graphicsComponent.setActualAnimation(animation);
	yen::BodyDef bodyDef;
	bodyDef.type = yen::BodyType::DYNAMIC;
	bodyDef.shapeSize = yen::fVector(10.0f, 10.0f);
	yen::PhysicsComponent physicsComponent(engine.physicsEngine, bodyDef, yen::fVector(5.0f, 5.0f));
	yen::ComponentManipulator graphicsComponentManipulator;
	engine.objectsManager->attachComponent(&graphicsComponentManipulator, cube, &graphicsComponent);
	yen::ComponentManipulator physicsComponentManipulator;
	engine.objectsManager->attachComponent(&physicsComponentManipulator, cube, &physicsComponent);


	engine.sceneManager->addObjectToScene(scene, camera);
	engine.sceneManager->addObjectToScene(scene, cube);
	engine.sceneManager->setActiveCameraofScene(scene, camera);
		
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
	yen::InputDef SpaceKeyDef;
	SpaceKeyDef.type = yen::InputType::KEYBOARD_KEY;
	SpaceKeyDef.name = "spaceKey";
	SpaceKeyDef.key = yen::inputs::Key::Space;
	yen::InputManipulator leftKey;
	yen::InputManipulator rightKey;
	yen::InputManipulator escapeKey;
	yen::InputManipulator spaceKey;
	engine.inputManager->createInput(&leftKey, leftKeyDef);
	engine.inputManager->createInput(&rightKey, rightKeyDef);
	engine.inputManager->createInput(&escapeKey, escapeKeyDef);
	engine.inputManager->createInput(&spaceKey, SpaceKeyDef);

	engine.sceneManager->initializeScene(scene);

	if (engine.run() == yen::Flag::OK)
	{
		while (engine.isRunning())
		{
			engine.step();

			if (engine.inputManager->isKeyPressed(leftKey))
				moveComponent.move(yen::fVector(0.1f, 0.0f));
			if (engine.inputManager->isKeyPressed(rightKey))
				moveComponent.move(yen::fVector(-0.1f, 0.0f));
			if (engine.inputManager->isKeyPressed(escapeKey))
				engine.stop();
			if (engine.inputManager->isKeyPressed(spaceKey))
				graphicsComponent.setActualAnimation(animation2);
				
		}
	}

	system("PAUSE");
	return 0;
}

