#include "TileMapping.h"

#define MAP_SIZE_X 16
#define MAP_SIZE_Y 8
#define MAP_TILE_SIZE_PX 96

SDL_Renderer* renderer;
SDL_Texture* texture;

TileMapping::TileMapping(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}


extern int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X] =	
{
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	{4,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,37,38,-1,-1},
	{4,39,-1,-1,-1,-1,-1,-1,-1,37,38,-1,-1,-1,-1,-1},
	{4,-1,-1,42,43,39,-1,-1,-1,-1,-1,-1,41,40,-1,-1},
	{4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
};

void TileMapping::Initialise()
{
	SDL_Surface * surface = IMG_Load("./GameObjects/Background.png");
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}


void TileMapping::Draw()
{
	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_X; j++)
		{
			SDL_Rect srcRect = { (MAP_DATA[i][j] % 8) * 64, ((MAP_DATA[i][j]) /8) *64, 64, 64 };
			SDL_Rect destroyRect = { j * MAP_TILE_SIZE_PX, i * MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX };


			SDL_RenderCopy(renderer, texture, &srcRect, &destroyRect);

		}
	}
}

void TileMapping::CleanUp()
{
	SDL_DestroyTexture(this->texture);
}