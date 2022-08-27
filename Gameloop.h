#pragma once
#include <SDL.h> //includes the SDL header file
#include <iostream>
#include "Player.h" //includes the header file named "Player" in this solution
#include "TileMapping.h"
#include "BulletManager.h"
#include "TextRenderer.h"
#include <SDL_ttf.h>
#include "Sound.h"
#include "MeteorManager.h"

#include "Particles.h"
//#include "Collision.h"

using namespace std;
class Player;
class TileMapping;
class BulletManager;

class Gameloop
{
public:

	SDL_Surface* renderFrame = NULL;

	Gameloop();

	bool Initialise();

	bool Input();

	void Update();

	void Draw();

	void CleanUp();

	bool getKeyDown(int keyCode) {
		if (keyCode > 0 && keyCode < 512) {
			return this->keyDown[keyCode];
		}
		return false;
	}



private:
	BulletManager* bullet;
	MeteorManager * enemy;
	Player* player;
	TileMapping* Tiles;
	TextRenderer * textRenderer;
	Sound * sound;
	Particles * particles;

	SDL_Window* window;
	SDL_Renderer* renderer;
	//SDL_Renderer * renderFrame;
	bool keyDown[512];
};