#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include "Player.h"
#include "Sound.h"
#include "TileMapping.h"
#define PI 3.14159265

using namespace std;
struct Bullet {
	int x, y, rotation, distance;
};
class BulletManager {
	friend class MeteorManager;
public:
	BulletManager(SDL_Renderer * renderer, Player * player) : renderer(renderer), player(player) {}
	void init()
	{
		SDL_Surface * surface = IMG_Load("./GameObjects/Bullet.png");
		this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
		SDL_FreeSurface(surface);
		sound = new Sound();
	}

	void processInput(bool * keyDown)
	{
		/*if (keyDown[SDL_SCANCODE_SPACE])
		{
			if (SDL_GetTicks() - 0 > 300)
			{
				bullets.push_back(Bullet{ float (player->position.x), float( player->position.y) , 0.0f , 0.0f });
				lastShot = SDL_GetTicks();
			}
		}*/

		/*const Uint8 *keys = SDL_GetKeyboardState(NULL);
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
			if (keys[SDL_SCANCODE_SPACE]) {
				if (SDL_GetTicks() - 0 > 300)
				{
					bullets.push_back(Bullet{ float(this->player->position.x), float(this->player->position.y) , 0.0f , 0.0f });
					lastShot = SDL_GetTicks();
				}
			}
		}*/

		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_SPACE]) {
			if (SDL_GetTicks() - lastShot >= SHOOT_TIMER_MS)
			{
				//sound->PlaySound(Sounds::HIT);
				bullets.push_back(Bullet{ this->player->position.x, this->player->position.y, 0 , 0 });
				lastShot = SDL_GetTicks();
			}
		}

	}


	void update()
	{

		for (auto &b : bullets)
		{
			b.x += BULLET_VELOCITY;
			
			//b.y += player->position.y;
			b.distance += BULLET_VELOCITY; //handles speed
		}
		auto remove = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) {return b.distance > 1000; });
		bullets.erase(remove, bullets.end());
	}

	void draw()
	{
		SDL_Point center = { 5,5 };
		for (auto &b : bullets)
		{
			SDL_Rect dest = { b.x + 60, b.y + 60, 50, 50 };
			SDL_RenderCopy(this->renderer, this->bulletTexture, 0, &dest);

			//SDL_Rect dest = { b.x,b.y,50,50 };
			//SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);
		}
	}

	void clean()
	{
		SDL_DestroyTexture(this->bulletTexture);
	}

private:
	SDL_Renderer * renderer;
	SDL_Texture * bulletTexture;
	vector<Bullet> bullets;
	Player * player;
	Sound * sound;
	int Score = 0;
	//BulletManager * bulletManager;

	const int SHOOT_TIMER_MS = 1500;
	const int BULLET_VELOCITY = 8;
	unsigned int lastShot = 0;
};