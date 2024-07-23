#pragma once
#include "Actor.h"
#include "Color.h"
#include "Particle.h"

class Enemy : public Actor
{

public:

	


	Enemy() = default;
	Enemy(const Transform& transform) : Actor{ transform } {}

	Enemy(float speed, const Transform& transform, Model* model) :
		Actor{ transform , model },
		m_speed{ speed }

	{}

	void Update(float dt);
	void Draw(Renderer& renderer);


	void OnCollision(Actor* actor);

	void HitAnimate(float dt);

private:

	std::vector<Particle> particles;
	float m_speed = 0;
	float m_firetimer = 0;
	bool left = false;
	bool hit = false;

	float shift_timer = .1f;
	float health = 30;
	

};