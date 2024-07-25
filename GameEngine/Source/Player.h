#pragma once
#include "Actor.h"

class Player : public Actor 
{

public:

	Player() = default;
	Player(const Transform& transform) : Actor{ transform } {}

	Player(float speed, const Transform& transform, Model* model) :
		Actor{ transform , model },
		m_speed{ speed }

	{}

	Player( const Transform& transform, Model* model) :
		Actor{ transform , model }
		

	{}

	void Draw(Renderer& renderer);
	void Update(float dt);
	void OnCollision(Actor* actor);
	float GetRadius() { return (m_model) ? (m_model->GetRadius() - 10) * m_transform.scale : 0; }
	bool GroundCheck();
	void Gravity(float dt);

	

private:

	float m_jumpSpeed = 4200;
	
	bool start_sound = true;

	float m_timerJumpMax = .125f;
	float m_jumpTimer = m_timerJumpMax;
	bool m_jumping = false;
	float m_speed = 1000;
	float m_firetimer = 0;
	float m_gravStrength = 1200;

	

};