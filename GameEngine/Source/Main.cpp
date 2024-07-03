#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "Color.h"

#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char* argv[])
{

	//Create Systems
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




	//main loop
	bool quit = false;
	while (!quit)
	{

		time.Tick();
		std::cout << time.GetTime() << std::endl;


		//INPUT
		input.Update();

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		//Update
		Vector2 mousePosition = input.GetMousePosition();

		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0)){
			std::cout << "mouse pressed\n";
			for (int i = 0; i < (random(300, 600)); i++) {
				particles.push_back(Particle{ mousePosition, {randomf(-300,300), randomf(-300,300)} });
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
		
		/*for (int i = 0;points.size() > 1 && i < points.size() - 1; i++)
		{
			
			renderer.DrawLine(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
			
		}*/
		color.randomize();
		renderer.SetColor(color.r, color.g, color.b, 0);
		for (Particle particle : particles) {
			particle.Draw(renderer);
		}
		
		// show screen
		renderer.EndFrame();
	}

	return 0;
}