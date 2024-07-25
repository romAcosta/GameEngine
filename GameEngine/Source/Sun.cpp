#include "Sun.h"
#include "Engine.h"
#include "Scene.h"

void Sun::Update(float dt)
{
	m_velocity.x = -25;
	if (m_transform.position.x < -5) {
		m_transform.position.x = g_engine.GetRenderer().GetWidth() + 5;
		if (m_scene->GetDay()) {
			m_scene->Night();
			m_model->ChangeColor(Color(1, 1, 1));
		}
		else {
			m_scene->Day();
			m_model->ChangeColor(Color(0, 0, 0));
		}

	}


	Actor::Update(dt);
}

void Sun::OnCollision(Actor* actor)
{
}
