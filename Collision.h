#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Gameloop.h"
#include "Player.h"

class Collision {
public:
	friend class Player;
	struct Sphere {
		int x, y, radius;
	};
	void Initialise();
	void LoadContent();
	bool Update();
	void Draw();
	void UnloadContent();
	Sphere * boundingSphere;



private:
	SDL_Window* window = NULL;
	SDL_Surface* renderFrame = NULL;
	SDL_Surface * surface;
	Player * player;
	SDL_Rect * rect;
};