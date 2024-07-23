#include "Enemy.h"
#include "Player.h"
#include "Scene.h"

void Enemy::Update(float dt)
{
	m_velocity.x = -m_speed;
	if (m_transform.position.x < -10) {
		m_destroyed = true;
	}
	Actor::Update(dt);
}

void Enemy::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player") {
		m_destroyed = true;
	}
}
