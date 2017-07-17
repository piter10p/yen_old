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

		void codeStepUpdate(yen::ObjectAccessInterface i)
		{
			if (timer.isTimeElapsed())
			{
				i.move(moveVector);
				moveVector.zero();
			}
		}
		void initialization(yen::ObjectAccessInterface i)
		{
			i.setPosition(yen::fVector(0.0f, 0.0f));

			timer.setElapseTime(0.001f);
			timer.start();
		}

		void move(yen::fVector moveVector)
		{
			this->moveVector = moveVector;
		}

		yen::Flag load() {return yen::Flag::OK;}

	private:
		yen::fVector moveVector;

		yen::time::FixedTimeLoopTimer timer;
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
		std::cout << "7" << std::endl;
	if (engine.inputManager->createInput(&rightKey, rightKeyDef) != yen::Flag::OK)
		std::cout << "8" << std::endl;
	if (engine.inputManager->createInput(&escapeKey, escapeKeyDef) != yen::Flag::OK)
		std::cout << "9" << std::endl;


	if(engine.sceneManager->loadScene(scene) != yen::Flag::OK)
		std::cout << "10" << std::endl;
	engine.sceneManager->initializeScene(scene);

	yen::time::LoopTimer timer;
	timer.setElapseTime(5);
	timer.start();

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

			//if (timer.isTimeElapsed())
				//engine.stop();
		}
	}

	system("PAUSE");
	return 0;
}

