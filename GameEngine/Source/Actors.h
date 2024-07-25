#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Prop.h"
#include "Sun.h"
#include "Models.h"
#include <memory>

struct Actors {

	

	
	std::unique_ptr<Actor> floor() {
		auto floor = std::make_unique< Prop>(Transform{ {0,g_engine.GetRenderer().GetHeight() - 100},0,1 }, modLib.floor());
		floor->SetTag("Floor");
		return floor;
	}

	std::unique_ptr<Actor> sun() {
		auto sun = std::make_unique< Sun>(Transform{ {700,100} ,0,70 }, modLib.ball());
		return sun;
	}
	

	std::unique_ptr<Actor> player(Color color) {
		Transform transform{ {70, g_engine.GetRenderer().GetHeight() >> 1},0,5 };
		auto player = std::make_unique< Player>(transform, modLib.player_model(color));
		return player;

	}

	std::unique_ptr<Actor> bullet(Vector2 position) {
		Transform transform{ position + Vector2{50,-40},.4f, 1.0f};

		auto bullet = std::make_unique< Bullet>(400.0f, transform, modLib.fireball());
		bullet->SetLifespan(.6f);
		bullet->SetTag("Player");
		return bullet;
	}

	std::unique_ptr<Actor> building(float speed) {
		Transform transform{ {g_engine.GetRenderer().GetWidth() + 20, (g_engine.GetRenderer().GetHeight() - 130)},0,7};
		std::unique_ptr<Enemy> building = std::make_unique< Enemy>(speed,transform, modLib.building());
		building->SetTag("Enemy");
		return building;

	}

	

};


extern Actors actorLib;