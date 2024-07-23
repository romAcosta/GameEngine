#include "Player.h"
#include "Engine.h"
#include "Bullet.h"
#include "Scene.h"
#include "Actors.h"
#include "Particle.h"
#include <iostream>

std::vector<Particle> particles;
Color breathColors[] = {Color{0,1,1},Color{0.5,0.5,0.5}, Color{0.05,0.45,0.58}};

void Player::Draw(Renderer& renderer) {

	for (Particle& particle : particles) {
		particle.Draw(renderer);

	}

	Actor::Draw(renderer);
}




void Player::Update(float dt)
{
	





	//fire
	m_firetimer -= dt;
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_SPACE)&& GroundCheck()) {

		

		if (m_firetimer <= 0) {
		m_firetimer = 0.1f;

			m_scene->AddActor(actorLib.bullet(m_transform.position));
		}

		
		

		for (int i = 0; i < (random(300, 600)); i++) {
			particles.push_back(Particle{ m_transform.position + Vector2{50,-40}, randomOnUnitCircle(22,27) * randomf(250,400), breathColors[random(2)],.6f});
		}
		
		
		
	}


	
	//Ground check and jumping
	if (GroundCheck() && !m_jumping) {
		
		m_velocity.y = 0;


		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_UP)) {


			m_jumping = true;
		}
		
	}
	else if (!m_jumping){
		Gravity(dt);
	}
	
	if (m_jumping ) {
		m_velocity.y -= m_jumpSpeed * dt;
		m_jumpTimer -= dt;
	}
	
	if (m_jumpTimer <= 0) {
		m_jumping = false;
		m_jumpTimer = m_timerJumpMax;
	}

	for (Particle& particle : particles) {
		particle.Update(dt);

	}

	particles.erase(
		std::remove_if(particles.begin(),	particles.end(), [](Particle& particle) { return particle.lifespan <= 0; }), particles.end()
	);

	Actor::Update(dt);
	
	
}

void Player::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy") {
		m_destroyed = true;
	}

	
}

bool Player::GroundCheck()
{
	float floorHeight = actorLib.floor()->GetTransform().position.y -(m_model->GetRadius() )*4;
	if (m_transform.position.y >= floorHeight) {
		
		return true;
	}
	return false;
}

void Player::Gravity(float dt)
{
	
	m_velocity.y += m_gravStrength * dt ;

	if (m_velocity.y >= m_speed) {
		m_velocity.y = m_speed;
	}



}




