#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"

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

	std::vector<Vector2> points;
	/*for (int i = 0; i < 100; i++){
		points.push_back(Vector2{ rand() % 800, rand() % 800 });
	}*/

	
	bool quit = false;
	while (!quit)
	{
		

		input.Update();

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}

		//Update
		Vector2 mousePosition = input.GetMousePosition();
		std::cout << mousePosition.x << std::endl;



		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0)){
			std::cout << "mouse pressed\n";
			points.push_back(mousePosition);
		}

		if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0)) {
			float distance = (points.back() - mousePosition).Length();
			if (distance > 5) {
				points.push_back(mousePosition);
			}
			//points.push_back(mousePosition);
		}



		
		/*for (Vector2 point : points) {
			point = point + 1.0f;
		}*/
		//// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		

		// draw line
		renderer.SetColor(20, 200, 100, 0);
		for (int i = 0;points.size() > 1 && i < points.size() - 1; i++)
		{
			
			renderer.DrawLine(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
			
		}
		
		// show screen
		renderer.EndFrame();
	}

	return 0;
}