#include "Engine.h"
#include "Player.h"
#include "Scene.h"
#include "Enemy.h"
#include "Color.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <SDL_ttf.h>


int main(int argc, char* argv[])
{
	g_engine.Initialize();


	//Create Systems
	


	Time time;

	Font* font = new Font();
	font->Load("Finland.ttf", 20);


	Text* text = new Text(font);
	text->Create(g_engine.GetRenderer(), "Hello World", Color{ 1.0f, 1.0f, 1.0f, 1.0f });

	std::vector<Vector2> points;
	points.push_back(Vector2{ -5, -5});
	points.push_back(Vector2{ -4, -6 });
	points.push_back(Vector2{ 2, -5 });
	points.push_back(Vector2{ 2, -3});
	points.push_back(Vector2{ -1, -2 });
	points.push_back(Vector2{ 2, -1});
	points.push_back(Vector2{ 2, 0 });
	points.push_back(Vector2{ 1, 1 });
	points.push_back(Vector2{ -1,1 });
	points.push_back(Vector2{ -1, 4 });
	points.push_back(Vector2{ 1, 3});
	points.push_back(Vector2{ 1, 4 });
	points.push_back(Vector2{ -1, 5 });
	points.push_back(Vector2{ -1, 8 });
	points.push_back(Vector2{ -2, 8 });
	points.push_back(Vector2{ -3, 6 });
	points.push_back(Vector2{ -4, 8 });
	points.push_back(Vector2{ -5, 8 });
	points.push_back(Vector2{ -5, -5});

	



	Color color{ 1, 1, 1};
	Model* model = new Model{ points, color };
	Model* eModel = new Model{ points, Color{1,0,0} };
	Vector2 position{ 200, 100 };
	float rotation = 0;

	Transform transform{ {g_engine.GetRenderer().GetWidth() >> 1, g_engine.GetRenderer().GetHeight() >> 1},0,5};

	Player* player = new Player(400, transform,model);
	player->SetDamping(2.0f);
	player->SetTag("Player");
	

	Scene* scene = new Scene();
	scene->AddActor(player);

	
	float spawnTimer = 2;

	
	

	//Sound Load
	


	//main loop
	bool quit = false;
	while (!quit)
	{
		g_engine.GetAudio().Update();


		time.Tick();
		
		g_engine.GetAudio().AddSound("bass.wav");

		//INPUT
		g_engine.GetInput().Update();

		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		//Sound Input
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_Q) && !g_engine.GetInput().GetPrevKeyDown(SDL_SCANCODE_Q)) {
			g_engine.GetAudio().PlaySound("bass.wav");
		}
		/*
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) {
			audio->playSound(sounds.at(1), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) {
			audio->playSound(sounds.at(2), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_A) && !input.GetPrevKeyDown(SDL_SCANCODE_A)) {
			audio->playSound(sounds.at(3), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_S) && !input.GetPrevKeyDown(SDL_SCANCODE_S)) {
			audio->playSound(sounds.at(4), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_D) && !input.GetPrevKeyDown(SDL_SCANCODE_D)) {
			audio->playSound(sounds.at(5), 0, false, nullptr);
		}*/

		/*spawnTimer -= time.GetDeltaTime();
		if (spawnTimer <= 0) {
			auto* enemy = new Enemy(200, Transform{ {random(g_engine.GetRenderer().GetWidth()),random(g_engine.GetRenderer().GetHeight())},0,4 }, eModel);
			enemy->SetTag("Enemy");
			scene->AddActor(enemy);
			spawnTimer = 2;
		}*/



		//Update
		
		scene->Update(time.GetDeltaTime());
	


		
		





		


		
		



		

		
		// clear screen
		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();

		

		// draw line
		

		text->Draw(g_engine.GetRenderer(), 40, 40);

		scene->Draw(g_engine.GetRenderer());
		
		


		// show screen
		g_engine.GetRenderer().EndFrame();
	}

	return 0;
}