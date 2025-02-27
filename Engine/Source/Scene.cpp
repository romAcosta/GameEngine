#include "Scene.h"
#include "Actor.h"
#include "Model.h"
#include "Engine.h"
#include "Transform.h"
#include <algorithm>

void Scene::Update(float dt)
{

	if (!game_over) {
		for (auto& actor : m_actors) {
			actor->Update(dt);
		}
	}


	

	m_actors.erase(
		std::remove_if(m_actors.begin(), m_actors.end(), [](auto& actor) { return actor->m_destroyed; }), m_actors.end()
	);

	//collision

	for (auto& actor1 : m_actors) {
		for (auto& actor2 : m_actors) {
			if (actor1 == actor2) continue;
			
			Vector2 direction = actor1->GetTransform().position - actor2->GetTransform().position;
			float distance = direction.Length();

			float radius = actor1->GetRadius() + actor2->GetRadius();

			if (distance <= radius) {
				actor1->OnCollision(actor2.get());
				actor2->OnCollision(actor1.get());
			}
		}
	}

}

void Scene::Draw(Renderer& renderer)
{
	
	for (auto& actor : m_actors) {
		actor->Draw(renderer);
	}
	
}

void Scene::AddActor(std::unique_ptr < Actor> actor)
{
	actor-> m_scene = this;
	
	m_actors.push_back(std::move(actor));
}
