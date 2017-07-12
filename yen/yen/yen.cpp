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


int main()
{
	yen::Engine engine;

	EngineConfiguration configuration;
	engine.initialize(configuration);

	yen::AnimationResourceDef animationDef;
	animationDef.path = "data\\anim";
	animationDef.frameRate = 60;
	yen::AnimationManipulator aManipulator = engine.resourceManager->addAnimationResource(animationDef);
	
	yen::ObjectManipulator oManipulator = engine.objectsManager->createObject();
	yen::GraphicsComponent gComponent(engine.graphicsEngine);
	gComponent.setAnimation(aManipulator);
	yen::ComponentManipulator cManipulator;
	engine.objectsManager->attachComponent(&cManipulator, oManipulator, &gComponent);

	yen::SceneManipulator sManipulator = engine.sceneManager->createScene();
	engine.sceneManager->addObjectToScene(sManipulator, oManipulator);

	engine.sceneManager->loadScene(sManipulator);
	engine.sceneManager->initializeScene(sManipulator);

	yen::time::LoopTimer timer;
	timer.setElapseTime(4);
	timer.start();
	
	if (engine.run() == yen::Flag::OK)
	{
		while (engine.isRunning())
		{
			engine.step();

			if (timer.isTimeElapsed())
				engine.stop();
		}
	}

	system("PAUSE");
	return 0;
}

