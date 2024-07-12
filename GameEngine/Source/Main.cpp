#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "Color.h"
#include "MathUtils.h"
#include "Model.h"
#include "Transform.h"

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fmod.hpp>

int main(int argc, char* argv[])
{

	//Create Systems
	// create audio system
	FMOD::System* audio;
	FMOD::System_Create(&audio);

	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);


	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;

	

	
	
	std::vector<Particle> particles;
	/*for (int i = 0; i < 1000; i++) {
		particles.push_back(Particle{ {rand() % 800, rand() % 800}, {randomf(300),0.0f}});
	}*/


	float offset = 0;

	std::vector<Vector2> points;
	points.push_back(Vector2{ 0, 5});
	points.push_back(Vector2{ 1, 4 });
	points.push_back(Vector2{ 7, 5 });
	points.push_back(Vector2{ 7, 7});
	points.push_back(Vector2{ 4, 8 });
	points.push_back(Vector2{ 7, 9 });
	points.push_back(Vector2{ 7, 10 });
	points.push_back(Vector2{ 6, 11 });
	points.push_back(Vector2{ 4,11 });
	points.push_back(Vector2{ 4, 14 });
	points.push_back(Vector2{ 6, 13 });
	points.push_back(Vector2{ 6, 14 });
	points.push_back(Vector2{ 4, 15 });
	points.push_back(Vector2{ 4, 18 });
	points.push_back(Vector2{ 3, 18 });
	points.push_back(Vector2{ 2, 16 });
	points.push_back(Vector2{ 1, 18 });
	points.push_back(Vector2{ 0, 18 });
	points.push_back(Vector2{ 0, 5 });



	Color color{ 1, 1, 1};
	Model model{ points, color };
	Vector2 position{ 400, 300 };
	float rotation = 0;

	Transform transform{ {renderer.GetWidth() >> 1, renderer.GetHeight() >> 1},0,5 };

	


	//Sound Load
	FMOD::Sound* sound = nullptr;
	std::vector<FMOD::Sound*> sounds;
	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound); //0
	sounds.push_back(sound);
	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);//1
	sounds.push_back(sound);
	audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);//2
	sounds.push_back(sound);
	audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);//3
	sounds.push_back(sound);
	audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);//4
	sounds.push_back(sound);
	audio->createSound("cowbell.wav", FMOD_DEFAULT, 0, &sound);//5
	sounds.push_back(sound);


	//main loop
	bool quit = false;
	while (!quit)
	{
		audio->update();


		time.Tick();
		std::cout << time.GetTime() << std::endl;


		//INPUT
		input.Update();

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		//Sound Input
		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q)) {
			audio->playSound(sounds.at(0), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) {
			audio->playSound(sounds.at(1), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) {
			audio->playSound(sounds.at(2), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_A) && !input.GetPrevKeyDown(SDL_SCANCODE_A)) {
			audio->playSound(sounds.at(3), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_S) && !input.GetPrevKeyDown(SDL_SCANCODE_S)) {
			audio->playSound(sounds.at(4), 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_D) && !input.GetPrevKeyDown(SDL_SCANCODE_D)) {
			audio->playSound(sounds.at(5), 0, false, nullptr);
		}





		//Update
		Vector2 mousePosition = input.GetMousePosition();

		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0)){
			std::cout << "mouse pressed\n";
			for (int i = 0; i < (random(300, 600)); i++) {
				particles.push_back(Particle{ mousePosition, randomOnUnitCircle() * randomf(500)});
			}
			
		}


		
		float thrust = 0;
		if (input.GetKeyDown(SDL_SCANCODE_LEFT))    transform.rotation -= Math::DegToRad(100) * time.GetDeltaTime();
		if (input.GetKeyDown(SDL_SCANCODE_RIGHT))    transform.rotation += Math::DegToRad(100) * time.GetDeltaTime();


		if (input.GetKeyDown(SDL_SCANCODE_UP))        thrust = 40;
		if (input.GetKeyDown(SDL_SCANCODE_DOWN))    thrust = -40;

		Vector2 velocity = Vector2{ thrust, 0.0f }.Rotate( transform.rotation);
		transform.position += (velocity * time.GetDeltaTime());
		transform.position.x = Math::Wrap(transform.position.x, (float)renderer.GetWidth());
		transform.position.y = Math::Wrap(transform.position.y, (float)renderer.GetHeight());





		


		position = position + (velocity * time.GetDeltaTime());
		rotation = rotation + time.GetDeltaTime();
		



		for (Particle& particle: particles) {
			particle.Update(time.GetDeltaTime());
			/*if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;*/
		}

		
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		

		// draw line
		
		
		


		
		
		for (Particle particle : particles) {
			particle.Draw(renderer);
		}

		renderer.SetColor(255, 255, 255, 0);
		model.Draw(renderer, transform);
		
		


		// show screen
		renderer.EndFrame();
	}

	return 0;
}