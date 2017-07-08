// yen.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "ObjectsManager.h"
#include "GraphicsComponent.h"
#include "GraphicsEngine.h"


int main()
{
	yen::GraphicsEngine gEngine;
	yen::ObjectsManager manager;
	yen::ObjectManipulator objectManipulator = manager.createObject();
	
	yen::GraphicsComponent *component = new yen::GraphicsComponent(&gEngine);
	yen::ComponentManipulator componentManipulator = manager.attachComponent(objectManipulator, component);
	manager.removeComponent(objectManipulator, componentManipulator);
	
	std::cout << manager.removeObject(objectManipulator);

	system("PAUSE");
	return 0;
}

