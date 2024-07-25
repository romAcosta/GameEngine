#pragma once
#include "Actor.h"




class Sun: public Actor {

public:

	Sun( const Transform& transform, Model* model) :
		Actor{ transform , model }
	{}

	void Update(float dt);
	void OnCollision(Actor* actor);

private:


};