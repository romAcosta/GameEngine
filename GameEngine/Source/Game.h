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
		GAMEOVER


	};

public:

	bool Initialize();
	void Update(float dt);
	void Draw(Renderer& renderer);
	

private:

	std::map<std::string,Scene*> m_scenes;
	Scene* m_currentScene;
	
	state current_state = TITLE;
	Font* font = new Font();
	
	int score;


	Text* text;
	Scene* scene ;

	
};