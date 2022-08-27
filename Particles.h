#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <list>

using namespace std;

class Particles {
public:

	Particles(SDL_Renderer * renderer);
	virtual ~Particles();

	void Init();

	void Update();

	void Draw();


private:
	SDL_Surface * particleSurface;
	list<SDL_Rect> particlePositions;

	Uint32 emissionRate = 400;
	Uint32 emissionRange = 90;
	Uint32 Gravity = 2;

	Uint32 lastParticleSpawn;
	Uint32 nextParticleSpawn;

	SDL_Renderer * renderer;
	SDL_Texture * snowtexture;
};