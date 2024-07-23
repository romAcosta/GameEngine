#pragma once
#include "Model.h"
#include "Engine.h"
#include <vector>;

struct Models
{

	Model* floor() {

		std::vector<Vector2> points;
		points.push_back(Vector2{ 0,0});
		points.push_back(Vector2{ g_engine.GetRenderer().GetWidth(), 0});
		
		Model* model = new Model{ points , Color{0.82,0.71,0.55} };

		return model;

	}

	Model* player_model(Color color) {
		std::vector<Vector2> points;

		points.push_back(Vector2{ 4, -12 });
		points.push_back(Vector2{ 5, -12 });
		points.push_back(Vector2{ 7, -11 });
		points.push_back(Vector2{ 5, -11 });
		points.push_back(Vector2{ 5, -10 });
		points.push_back(Vector2{ 6, -10 });
		points.push_back(Vector2{ 7, -11 });
		points.push_back(Vector2{ 5, -12 });
		points.push_back(Vector2{ 7, -12 });
		points.push_back(Vector2{ 9, -11 });
		points.push_back(Vector2{ 10, -10 });
		points.push_back(Vector2{ 10, -9 });
		points.push_back(Vector2{ 8, -9 });
		points.push_back(Vector2{ 10, -9 });
		points.push_back(Vector2{ 10, -8 });
		points.push_back(Vector2{ 8, -7 });
		points.push_back(Vector2{ 7, -7 });
		points.push_back(Vector2{ 6, -5 });
		points.push_back(Vector2{ 6, -4 });
		points.push_back(Vector2{ 7, 0 });
		points.push_back(Vector2{ 9, 2 });
		points.push_back(Vector2{ 10, 3 });
		points.push_back(Vector2{ 9, 3 });
		points.push_back(Vector2{ 10, 4 });
		points.push_back(Vector2{ 9, 4 });
		points.push_back(Vector2{ 10, 5 });
		points.push_back(Vector2{ 9, 5 });
		points.push_back(Vector2{ 6, 4 });
		points.push_back(Vector2{ 4, 1 });
		points.push_back(Vector2{ 3, -4 });
		points.push_back(Vector2{ 4, 1 });
		points.push_back(Vector2{ 6, 4 });
		points.push_back(Vector2{ 7, 7 });
		points.push_back(Vector2{ 7, 11 });
		points.push_back(Vector2{ 8, 12 });
		points.push_back(Vector2{ 4, 12 });
		points.push_back(Vector2{ 4, 7 });
		points.push_back(Vector2{ 3, 10 });
		points.push_back(Vector2{ 3, 11 });
		points.push_back(Vector2{ 4, 12 });
		points.push_back(Vector2{ 0, 12 });
		points.push_back(Vector2{ 0, 7 });
		points.push_back(Vector2{ -2, 9 });
		points.push_back(Vector2{ -5, 11 });
		points.push_back(Vector2{ -10, 11 });
		points.push_back(Vector2{ -7, 8 });
		points.push_back(Vector2{ -4, 6 });
		points.push_back(Vector2{ -2, 2 });
		points.push_back(Vector2{ -1, 0 });
		points.push_back(Vector2{ 0, -6 });
		points.push_back(Vector2{ 1, -10 });
		points.push_back(Vector2{ 2, -11 });
		points.push_back(Vector2{ 4, -12 });
		points.push_back(Vector2{ 1, -12 });
		points.push_back(Vector2{ 1, -10 });
		points.push_back(Vector2{ 0, -10 });
		points.push_back(Vector2{ 0, -6 });
		points.push_back(Vector2{ -1, -6 });
		points.push_back(Vector2{ -1, 0 });
		points.push_back(Vector2{ -2, 0 });
		points.push_back(Vector2{ -2, 2 });
		points.push_back(Vector2{ -4, 2 });
		points.push_back(Vector2{ -4, 6 });
		points.push_back(Vector2{ -7, 6 });
		points.push_back(Vector2{ -7, 8 });


		
		Model* model = new Model{ points, color };

		return model;
	}

	Model* fireball() {
		std::vector<Vector2> points;
		points.push_back(Vector2{ 1, 0 });
		points.push_back(Vector2{ -1, -1 });
		points.push_back(Vector2{ -1, 1 });
		points.push_back(Vector2{ 1, 0 });
		Model* model = new Model{ points, Color{ 0, 1, 1 } };
		return model;
	}

	Model* building() {

		std::vector<Vector2> points;
		points.push_back(Vector2{ -3, -2 });
		points.push_back(Vector2{ -3, -3 });
		points.push_back(Vector2{ 1, -3 });
		points.push_back(Vector2{ 1, -4 });
		points.push_back(Vector2{ 0, -4 });
		points.push_back(Vector2{ 0, -3 });
		points.push_back(Vector2{ 2, -3 });
		points.push_back(Vector2{ 2, -2 });
		points.push_back(Vector2{ 2, 4 });
		points.push_back(Vector2{ -1, 4 });
		points.push_back(Vector2{ -1, 2 });
		points.push_back(Vector2{ 0, 2 });
		points.push_back(Vector2{ 0, 4 });
		points.push_back(Vector2{ -3, 4 });
		points.push_back(Vector2{ -3, -2 });
		points.push_back(Vector2{ -1, -2 });
		points.push_back(Vector2{ -1, 0 });
		points.push_back(Vector2{ -2, 0 });
		points.push_back(Vector2{ -2, -2 });
		points.push_back(Vector2{ 1, -2 });
		points.push_back(Vector2{ 1, 0 });
		points.push_back(Vector2{ 0, 0 });
		points.push_back(Vector2{ 0, -2 });
		points.push_back(Vector2{ 2, -2 });
		Model* model = new Model{ points, Color{ 0.71f,0.40f,0.11f } };
		return model;
	}

	Model* ball(Color color) {

		std::vector<Vector2> points;
		for (int i = 0; i < 361; i++) {
			points.push_back(OnUnitCircle(i));
		}
		
		Model* model = new Model{ points, Color{0,0,0 } };
		return model;
	}







};

extern Models modLib;