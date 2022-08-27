#include "MeteorManager.h"

void MeteorManager::init() {

	SDL_Surface * surface = IMG_Load("./GameObjects/Enemy.png");
	SDL_Surface * surface1 = IMG_Load("./GameObjects/HP.png");
	SDL_Surface * surface2 = IMG_Load("./GameObjects/HP2.png");
	this->meteorTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	this->HPTexture = SDL_CreateTextureFromSurface(this->renderer, surface1);
	this->HP2Texture = SDL_CreateTextureFromSurface(this->renderer, surface2);
	SDL_FreeSurface(surface);

	this->dest1.x = 225;
	this->dest1.y = 640;
	this->dest1.w = 256;
	this->dest1.h = 32;

	lastSpawn = SDL_GetTicks();
	meteors.push_back(Meteor{ 1280, -12 });

	sphere = new Sphere(rect.x + (rect.w / 2),
		rect.y + (rect.h / 2), rect.w / 2);
	}

void MeteorManager::update() {


			for (auto &m : meteors) {
				//m.y = 525;
				SDL_Rect playerRect = { this->player->position.x,525, 32, 32 };
				SDL_Rect EnemyTerrainColl = { this->player->random.x + 10,525, 50, 50 };
				SDL_Rect BulletTerrainColl = { this->player->random.x - 35,525, 50, 50 };
				SDL_Rect meteorRect = { m.x - 20, 525, 32, 32 };
				SDL_Rect nullRect;
				m.x -= 2;
				if (score >= 10)
				{
					m.x -= 3;
					if (score >= 20)
					{
						m.x -= 4;
					}
				}
				if (m.x > 1280 + 32) {
					m.x = -32;
				}
				for (auto &b : bulletManager->bullets) {
					SDL_Rect bulletRect = { b.x + 60, 525, 10, 10 };
					if (SDL_IntersectRect(&bulletRect, &meteorRect, &nullRect)) {
						score++;
						b.distance = 1000; // move bullet
						m.x = 0xCCCCCCCC; // moves enemy
						//meteors.push_back(Meteor{ 1280, -12 });
					}
					if (SDL_IntersectRect(&bulletRect, &BulletTerrainColl, &nullRect)) {
						b.distance = 1000; // move bullet
					}
					auto remove = std::remove_if(meteors.begin(), meteors.end(), [](const Meteor& m) {return m.x == 0xCCCCCCCC; });
					meteors.erase(remove, meteors.end());
				}
				if (SDL_IntersectRect(&playerRect, &meteorRect, &nullRect)) {
					dest1.w -= 16;
					m.x = 0xCCCCCCCC;
					//meteors.push_back(Meteor{ 1280, -12 });
					if (dest1.w <= 0)
					{
						exit(0);
					}
				}
				if (SDL_IntersectRect(&EnemyTerrainColl, &meteorRect, &nullRect)) {
					m.x = 0xCCCCCCCC;
					//meteors.push_back(Meteor{ 1280, -12 });
				}
			}

			if (SDL_GetTicks() - lastSpawn > 2000)
			{
				meteors.push_back(Meteor{ 1280, -12 });
				lastSpawn = SDL_GetTicks();
			}

		}
	

void MeteorManager::draw() {

	SDL_Rect dest2 = { 225, 640, 256 ,32, };
	SDL_RenderCopy(renderer, HP2Texture, 0, &dest2);

	SDL_RenderCopy(renderer, HPTexture, 0, &dest1);

	for (auto &m : meteors) {
		SDL_Rect dest = { m.x, 525, 32,32, };
		SDL_Rect destplayer = {player->position.x, 525, 32, 32};
		SDL_RenderCopy(renderer, meteorTexture, 0, &dest);
	}
}
void MeteorManager::clean() {
	SDL_DestroyTexture(this->meteorTexture);
}
