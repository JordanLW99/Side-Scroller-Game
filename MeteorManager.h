#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "BulletManager.h"
#include "TextRenderer.h"
#include "Player.h"
#include <math.h>

using namespace std;

class MeteorManager {
	friend class Player;
public:

	struct Meteor {
		int x, y;
	};
	MeteorManager(SDL_Renderer * renderer, BulletManager * bulletManager, Player * player) : renderer(renderer), bulletManager(bulletManager), player(player) {}

	struct Sphere {
		Sphere(int x, int y, int radius) : x(x), y(y), radius(radius) {}
		bool  CollisionWithSphere(Sphere& s) const {
			int diffX = s.x > x ? s.x - x : x - s.x;
			int diffY = s.y > y ? s.y - y : y - s.y;
			int vectorLength = sqrt(diffX * diffX + diffY * diffY);
			return vectorLength < (radius + s.radius);
			return false;
		}
	private:
		int x, y;
		int radius;
	};

	void init();
	void clean();
	void draw();
	void update();


private:
	vector<Meteor> meteors;
	SDL_Renderer * renderer;
	SDL_Texture * meteorTexture;
	SDL_Texture * HPTexture;
	SDL_Texture * HP2Texture;
	BulletManager * bulletManager;
	SDL_Rect dest1;
	Player * player;

	Sphere * sphere;
	SDL_Rect rect;

	long int lastSpawn;

};