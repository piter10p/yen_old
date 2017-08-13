// yen.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "yen.h"


int main()
{
	try
	{
		yen::Engine engine;

		engine.resourceManager->addLanguage("pl");

		EngineConfiguration configuration;
		engine.initialize(configuration);

		yen::AnimationResourceDef animationDef;
		animationDef.path = "anim";
		animationDef.frameRate = 60;
		yen::AnimationManipulator animation = engine.resourceManager->addAnimationResource(animationDef);
		animationDef.path += "2";
		animationDef.frameRate = 0;
		yen::AnimationManipulator animation2 = engine.resourceManager->addAnimationResource(animationDef);

		yen::FontManipulator fontManipulator = engine.resourceManager->addFontResource("Uni Sans Thin.otf");

		
		yen::StringManipulator sManipulator = engine.resourceManager->addStringResource("strings.xml");//------------------------

		yen::ObjectManipulator camera = engine.objectsManager->createObject(yen::fVector(engine.settingsManager->getGraphicsSettings().resolution.getX() / 2.0f, engine.settingsManager->getGraphicsSettings().resolution.getY() / 2.0f));
		yen::CameraComponent cameraComponent(engine.graphicsEngine);
		cameraComponent.setSize(yen::fVector(engine.settingsManager->getGraphicsSettings().resolution.getX(), engine.settingsManager->getGraphicsSettings().resolution.getY()));
		yen::ComponentManipulator cameraComponentManipulator;
		engine.objectsManager->attachComponent(&cameraComponentManipulator, camera, &cameraComponent);


		yen::SceneManipulator scene = engine.sceneManager->createScene();
		engine.sceneManager->setSceneGravity(scene, yen::fVector(0.0f, 10.0f));


		yen::ObjectManipulator cube = engine.objectsManager->createObject(yen::fVector(0.0f, 0.0f));
		engine.objectsManager->setLoadDistance(cube, 600.0f);
		yen::GraphicsComponent graphicsComponent(engine.graphicsEngine);
		graphicsComponent.addAnimation(animation);
		graphicsComponent.addAnimation(animation2);
		graphicsComponent.setActualAnimation(animation);
		yen::BodyDef bodyDef;
		bodyDef.type = yen::BodyType::DYNAMIC;
		bodyDef.shapeSize = yen::fVector(100.0f, 100.0f);
		bodyDef.offset = yen::fVector(50.0f, 50.0f);
		bodyDef.position = yen::fVector(100.0f, 0.0f);
		yen::PhysicsComponent physicsComponent(engine.physicsEngine, bodyDef);
		yen::ComponentManipulator graphicsComponentManipulator;
		engine.objectsManager->attachComponent(&graphicsComponentManipulator, cube, &graphicsComponent);
		yen::ComponentManipulator physicsComponentManipulator;
		engine.objectsManager->attachComponent(&physicsComponentManipulator, cube, &physicsComponent);

		yen::ObjectManipulator cube2 = engine.objectsManager->createObject(yen::fVector(0.0f, 0.0f));
		engine.objectsManager->setLoadDistance(cube2, 600.0f);
		yen::GraphicsComponent graphicsComponent2(engine.graphicsEngine);
		graphicsComponent2.addAnimation(animation);
		graphicsComponent2.setActualAnimation(animation);
		yen::ComponentManipulator c2GraphicsComponentManipulator;
		engine.objectsManager->attachComponent(&c2GraphicsComponentManipulator, cube2, &graphicsComponent2);

		yen::ObjectManipulator text = engine.objectsManager->createObject(yen::fVector(150.0f, 0.0f));
		engine.objectsManager->setLoadDistance(text, 0.0f);
		yen::GraphicsComponent textGComp(engine.graphicsEngine, yen::GraphicsComponentContent::TEXT);
		yen::TextAttributes tAttr;
		tAttr.charactersSize = 12;
		tAttr.textColor = yen::Color(0, 0, 0, 255);
		textGComp.setFontResource(fontManipulator);
		textGComp.setString(sManipulator, "car");
		textGComp.setTextAttributes(tAttr);
		yen::ComponentManipulator textGComptManipulator;
		engine.objectsManager->attachComponent(&textGComptManipulator, text, &textGComp);


		engine.sceneManager->addObjectToScene(scene, camera);
		engine.sceneManager->addObjectToScene(scene, cube);
		engine.sceneManager->addObjectToScene(scene, text);
		engine.sceneManager->addObjectToScene(scene, cube2);

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

				//if (engine.inputManager->isKeyPressed(leftKey))
					//moveComponent.move(yen::fVector(0.1f, 0.0f));
				//if (engine.inputManager->isKeyPressed(rightKey))
					//moveComponent.move(yen::fVector(-0.1f, 0.0f));
				if (engine.inputManager->isKeyPressed(escapeKey))
					engine.stop();
				if (engine.inputManager->isKeyPressed(spaceKey))
					graphicsComponent.setActualAnimation(animation2);

			}
		}
	}
	catch (...)
	{
		std::cout << "ERROR";
	}

	

	system("PAUSE");
	return 0;
}

