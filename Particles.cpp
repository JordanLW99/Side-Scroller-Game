#include "Particles.h"

Particles::Particles(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

Particles::~Particles()
{
}

void Particles::Init()
{
	SDL_Surface * particleSurface = IMG_Load("./GameObjects/snow.png");
	this->snowtexture = SDL_CreateTextureFromSurface(this->renderer, particleSurface);
	SDL_FreeSurface(particleSurface);
	//particlePositions.push_back(r);
	//lastParticleSpawn = SDL_GetTicks();
}

void Particles::Update()
{
	//particlePositions.remove_if([](SDL_Rect r) {return r.x >= 1290 || r.y >= 400; });
	if (SDL_GetTicks() - lastParticleSpawn >= nextParticleSpawn)
	{
		lastParticleSpawn = SDL_GetTicks();
		nextParticleSpawn = emissionRate + (rand() % emissionRange);
		SDL_Rect r;
		r.x = (rand() % 1270);
		r.y = 0;
		particlePositions.push_back(r);
		//r.x = (rand() % 500);
	}
	for (auto& particle : particlePositions) {
		particle.y += Gravity;
	}
	//r.y += 4;
}

void Particles::Draw()
{
	for (auto& particle : particlePositions) {
		SDL_Rect rect = { particle.x, particle.y, 20, 20 };
		SDL_RenderCopy(this->renderer, this->snowtexture, 0, &rect);
	}
}
