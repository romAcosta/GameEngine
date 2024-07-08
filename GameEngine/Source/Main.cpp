#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "Color.h"
#include "MathUtils.h"

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

	Color color;

	std::vector<Vector2> points;
	
	std::vector<Particle> particles;
	/*for (int i = 0; i < 1000; i++) {
		particles.push_back(Particle{ {rand() % 800, rand() % 800}, {randomf(300),0.0f}});
	}*/


	float offset = 0;



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

		//if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0)) {
		//	float distance = (points.back() - mousePosition).Length();
		//	if (distance > 5) {
		//		points.push_back(mousePosition);
		//	}
		//	//points.push_back(mousePosition);
		//}



		for (Particle& particle: particles) {
			particle.Update(time.GetDeltaTime());
			/*if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x < 0) particle.position.x = 800;*/
		}

		
		//// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		

		// draw line
		
		
		/*color.randomize();*/


		renderer.SetColor(random(255), random(255), random(255), 0);
		
		for (Particle particle : particles) {
			particle.Draw(renderer);
		}

		float radius = 60;
		offset -= (90 * time.GetDeltaTime());
		for (float angle = 0; angle < 360; angle += 360.0f / 300.0f) {
			float x = Math::Cos(Math::DegToRad(angle + offset)) * Math::Sin(offset * 0.01f + angle ) * radius;
			float y = Math::Sin(Math::DegToRad(angle + offset)) * Math::Cos(offset * 0.001f) * radius;
			float x1 = Math::Cos(Math::DegToRad(angle + offset)) * (200 + radius);
			float y1 = Math::Sin(Math::DegToRad(angle + offset)) * (200 + radius );
			renderer.DrawLine(x + 400, y + 300, x1 + 400, y1 + 300);

			//renderer.DrawRect(x + 400, y + 300, x1 + 400, y1 + 300);
		}
		


		// show screen
		renderer.EndFrame();
	}

	return 0;
}