#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Gameloop.h"
#include "Player.h"

class TileMapping
{
public:
	TileMapping(SDL_Renderer*);
	void Initialise();
	void Draw();
	void CleanUp();
private:
	SDL_Rect position;
	SDL_Texture * texture;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player * player;
};