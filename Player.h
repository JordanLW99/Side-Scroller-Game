#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Sound.h"

//#include "MeteorManager.h"
//#include "TextRenderer.h"
//#include "Gameloop.h"
extern int score;

class Player {
	friend class MeteorManager;
	friend class TileMapping;
	friend class TextRenderer;
public:

	Player(SDL_Renderer*renderer);
	void Initialise();
	virtual ~Player();
	bool Input(bool * keyDown);
	bool Update();
	void Draw();
	void CleanUp();
	SDL_Rect position;
	SDL_Rect random;

private:
	Sound * sound;
	SDL_Texture * texture;
	SDL_Texture * texture1;
	//SDL_Surface * renderFrame;
	//TextRenderer * textRenderer;
	SDL_Renderer * renderer;
	bool keyDown[512];
	bool keyUp[512];
	//Sphere * boundingSphere;
	//SDL_Surface * surface;
};