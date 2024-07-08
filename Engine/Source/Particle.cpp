#include "Particle.h"

void Particle::Update(float dt)
{
	if (lifespan != 0) {
		position = position + (velocity * dt);
		lifespan -= dt;
	}
	
}

void Particle::Draw(Renderer& renderer)
{
	
	if(!(lifespan <= 0)) renderer.DrawRect(position.x, position.y, 4.0f, 5.0f);

}
