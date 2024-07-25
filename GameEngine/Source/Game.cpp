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
	
	scene->AddActor(std::move(actorLib.player(Color{01,01,01})));
	scene->AddActor(std::move(actorLib.floor()));
	scene->AddActor(std::move(actorLib.sun()));
	m_scenes["Game"] = scene;
	m_currentScene = m_scenes.at("Game");
	font->Load("Finland.ttf", 20);
	title_font ->Load("Finland.ttf", 50);
	text = new Text(font);
	title_text = new Text(title_font);
	
	g_engine.GetAudio().PlaySound("roar.wav");
	

    return false;
	
}

float t = 5;
float musict = 32;
float spawnTimer = 1.5;
std::string Score;
void Game::Update(float dt)
{
	
	
	switch (current_state)
	{
	case Game::TITLE:
		if (t <= 0 && current_state == Game::TITLE) {
			current_state = Game::SHIFT;
			//std::cout << "SPACE" << std::endl;
		}
		else {
			t -= dt;
		}
		

		break;
	case Game::SHIFT:
		current_state = Game::GAME;
		g_engine.GetAudio().PlaySound("zilla-music.wav");
		
		break;
	case Game::GAME:
		
		if (musict <= 0) {
			g_engine.GetAudio().PlaySound("zilla-music.wav");
			musict = 32;
		}
		else {
			musict -= dt;
		}

		Score = "Score: " + score;
		score = scene->GetScore();

		m_currentScene->Update(dt);
		g_engine.GetAudio().Update();

		//INPUT
		g_engine.GetInput().Update();


		//Sound Input

		spawnTimer -= dt;
		if (spawnTimer <= 0) {

			scene->AddActor(std::move(actorLib.building(200 * game_speed)));
			spawnTimer = randomf(1, 3) / game_speed;
			game_speed += 0.01f;

		}
		m_currentScene->Update(dt);
		if (scene->GetGame()) {
			current_state = Game::GAMEOVER;
			t = 5;
		}
		break;
	case Game::GAMEOVER:
		g_engine.GetAudio().StopSound();
		t -= dt;
		if (t<= 0) {
			scene->GameOn();
			current_state = Game::RESTART;
			t = 5;
		}
		break;

	case Game::RESTART:
		Initialize();
		current_state = Game::TITLE;
		break;
	default:
		break;
	}
	
	
	
	
}

void Game::Draw(Renderer& renderer) {

	switch (current_state)
	{
	case Game::TITLE:
		title_text->Create(g_engine.GetRenderer(), "ZILLA-RUN", Color{ 1.0f, 0, 0, 1.0f });

		title_text->Draw(renderer, g_engine.GetRenderer().GetWidth()  - 500, g_engine.GetRenderer().GetHeight() >> 1);
		

		break;
	case Game::SHIFT:


		break;
	case Game::GAME:
		if (scene->GetDay()) {
			g_engine.GetRenderer().SetColor(235, 235, 235, 0);
		}
		else {
			g_engine.GetRenderer().SetColor(0, 0, 0, 0);
			
		}
		
		g_engine.GetRenderer().DrawRect(0, 0, g_engine.GetRenderer().GetWidth() * 2, g_engine.GetRenderer().GetHeight() * 2);
		m_currentScene->Draw(renderer);
		text->Draw(renderer, 40, 40);
		text->Create(g_engine.GetRenderer(), "Score: " + std::to_string(score), Color{ 1.0f, 0, 0, 1.0f });

		

		break;
	case Game::GAMEOVER:
		text->Create(g_engine.GetRenderer(), "Score: " + std::to_string(score), Color{ 1.0f, 0, 0, 1.0f });
		text->Draw(renderer, 370, 400);
		title_text->Create(g_engine.GetRenderer(), "GAME OVER", Color{ 1.0f, 0, 0, 1.0f });
		title_text->Draw(renderer, g_engine.GetRenderer().GetWidth() - 500, g_engine.GetRenderer().GetHeight() >> 1);
		break;
	default:
		break;
	}
	

}




