#include "Engine.h"
#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <SDL_ttf.h>


int main(int argc, char* argv[])
{
	g_engine.Initialize();


	//Create Systems
	Time time;
	Game* game = new Game();
	
	game->Initialize();

	//Sound Load
	


	//main loop
	bool quit = false;
	while (!quit)
	{
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		time.Tick();




		game->Update(time.GetDeltaTime());

		

		g_engine.GetRenderer().SetColor(0,0,0,0);
		g_engine.GetRenderer().BeginFrame();
		
		game->Draw(g_engine.GetRenderer());

		g_engine.GetRenderer().EndFrame();
	}
	g_engine.Shutdown();
	return 0;
}