#pragma once
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Transform.h"
#include "Models.h"
#include <map>
#include <string>

class Game {

public:
	enum state {
		TITLE,
		SHIFT,
		GAME,
		GAMEOVER,
		RESTART


	};

public:

	bool Initialize();
	void Update(float dt);
	void Draw(Renderer& renderer);
	

private:

	std::map<std::string,Scene*> m_scenes;
	Scene* m_currentScene;
	
	state current_state = Game::TITLE;
	Font* font = new Font();
	Font* title_font = new Font();
	int score;
	float game_speed = 1;

	Text* text;
	Text* title_text;
	Scene* scene ;

	
};