#include "Collision.h"

void Collision::Initialise() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}
	else {
		window = SDL_CreateWindow("SDL Tutorial 2 - Input", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 768, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return;
		}
		else {
			renderFrame = SDL_GetWindowSurface(window);
		}
	}

}

void Collision::LoadContent() {
	//[8] load in the two sprites. Set the
	// ships position and the burst to not draw.

}

bool Collision::Update() {

	//[14] Move the ship when arrow keys are pressed


	//[15] Check for collision between ship and burst


	return true;
}

void Collision::Draw() {
	//clear screen to cornflower blue
	SDL_FillRect(renderFrame, NULL, 0x6495ed);

	//[16] render the ship and burst


	SDL_UpdateWindowSurface(window);
}

void Collision::UnloadContent() {
	//[17] Release ship and burst sprites

}