#pragma once
#include "Actor.h"

class Prop : public Actor {

public:

	Prop() = default;
	Prop(const Transform& transform) : Actor{ transform } {}

	Prop( const Transform& transform, Model* model) :
		Actor{ transform , model }
		

	{}
	Prop(const Transform& transform, Model* model, float speed) :

		Actor{ transform , model },
		speed{speed}



	{}



	void Update(float dt);
	void OnCollision(Actor* actor);

	const Transform& GetTransform() { return m_transform; }

private:

	float speed = 0;
	


};