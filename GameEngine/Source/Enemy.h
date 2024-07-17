#pragma once
#include "Actor.h"

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

	void OnCollision(Actor* actor);

private:

	float m_speed = 0;
	float m_firetimer = 0;


};