#include "Game.h"
#include "Actors.h"
#include "Engine.h"
#include <iostream>
#include <memory>

bool Game::Initialize()
{

	//level
	scene = new Scene();
	
	score = 0;
	
	scene->AddActor(std::move(actorLib.player(Color{0,0,0})));
	scene->AddActor(std::move(actorLib.floor()));
	scene->AddActor(std::move(actorLib.building(300)));
	//scene->AddActor(std::move(actorLib.ball()));
	m_scenes["Game"] = scene;
	m_currentScene = m_scenes.at("Game");
	font->Load("Finland.ttf", 20);
	text = new Text(font);
	

    return false;
	
}
float spawnTimer = 1.5;
std::string Score;
void Game::Update(float dt)
{
	Score = "Score: " + score;
	score += 222 * dt;
	
	
	
	m_currentScene->Update(dt);

	g_engine.GetAudio().Update();


	



	//INPUT
	g_engine.GetInput().Update();

	/*if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
		quit = true;
	}*/
	//Sound Input
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_Q) && !g_engine.GetInput().GetPrevKeyDown(SDL_SCANCODE_Q)) {

	}
	

	spawnTimer -= dt;
	if (spawnTimer <= 0) {
		
		scene->AddActor(std::move(actorLib.building(250)));
		spawnTimer = 2;
	}



	//Update

	m_currentScene->Update(dt);





	// clear screen
	



	// draw line


	




	// show screen
	
}

void Game::Draw(Renderer& renderer) {
	g_engine.GetRenderer().SetColor(255, 255, 255, 0);
	g_engine.GetRenderer().DrawRect(0, 0, g_engine.GetRenderer().GetWidth() * 2, g_engine.GetRenderer().GetHeight() * 2);
	text->Draw(renderer, 40, 40);
	text->Create(g_engine.GetRenderer(), "Score: " + std::to_string(score), Color{ 1.0f, 0, 0, 1.0f });

	m_currentScene->Draw(renderer);

}




