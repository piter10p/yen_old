// yen.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "Engine.h"
#include "Flag.h"


int main()
{
	yen::Engine engine;

	engine.initialize();

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

