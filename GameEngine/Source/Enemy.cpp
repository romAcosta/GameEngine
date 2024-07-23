#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include "Engine.h"
#include <iostream>
#include <vector>


Color fireColors[] = { Color{1,1,0},Color{0.5,0.5,0.5}, Color{1,0,0} , Color{1,.65,0} };

void Enemy::Update(float dt)
{
	m_velocity.x = -m_speed;
	HitAnimate(dt);
	if (m_transform.position.x < -10) {
		m_destroyed = true;
	}
	
	if (health <= 0) {
		for (int i = 0; i < (5); i++) {
			particles.push_back(Particle{ m_transform.position + Vector2{3,-2}, randomOnUnitCircle(220,310) * Vector2 { randomf(20,50),randomf(50,100) }, fireColors[random(0,3)],.2f });
		}
		for (int i = 0; i < (5); i++) {
			particles.push_back(Particle{ m_transform.position + Vector2{-10,-2}, randomOnUnitCircle(220,310) * Vector2 { randomf(20,50),randomf(50,100) }, fireColors[random(0,3)],.2f });
		}
		for (int i = 0; i < (5); i++) {
			particles.push_back(Particle{ m_transform.position + Vector2{-4,30}, randomOnUnitCircle(220,310) * Vector2 { randomf(20,50),randomf(50,100) }, fireColors[random(0,3)],.2f });
		}
	}

	for (Particle& particle : particles) {
		particle.Update(dt);

	}
	particles.erase(
		std::remove_if(particles.begin(), particles.end(), [](Particle& particle) { return particle.lifespan <= 0; }), particles.end()
	);

	Actor::Update(dt);
	
}

void Enemy::Draw(Renderer& renderer)
{

	for (Particle& particle : particles) {
		particle.Draw(renderer);

	}

	Actor::Draw(renderer);


}

void Enemy::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player") {
		
		hit = true;
		m_scene->AddScore(1);
		

	}
	




}

void Enemy::HitAnimate(float dt)
{
	
	
		
	
	if (hit) {
		health -= 1;
		if (shift_timer > 0) {
			shift_timer -= dt;
			if (left) {
				m_velocity.x += 50;
			}
			else
			{
				m_velocity.x -= 50;
			}
		}
		else {
			shift_timer = .1f;
			left = (left) ? false : true;
		}
		

	}
	
	hit = false;
	


}




