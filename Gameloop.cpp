#include "Gameloop.h"

Gameloop::Gameloop(){
}

bool Gameloop::Initialise()
{

	for (int i = 0; i < 256; i++)
	{
		keyDown[i] = false;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not initialise SDL: " << SDL_GetError();
		return false;
	}
	window = SDL_CreateWindow(
		"SDL Sprite",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1280, 768,
		SDL_WINDOW_SHOWN
	);

	if (!window) {
		std::cerr << "Could not create SDL window: " << SDL_GetError();
		return false;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		return false;
	}
	Tiles = new TileMapping(this->renderer);
	Tiles->Initialise();
	//process initialisation for game classes here
	player = new Player(this->renderer);
	player->Initialise();
	//collision->Initialise();
	bullet = new BulletManager(this->renderer, this->player);
	bullet->init();
	enemy = new MeteorManager(this->renderer, this->bullet, this->player);
	enemy->init();
	textRenderer = new TextRenderer("comic.ttf", 24);
	sound = new Sound();
	//sound->PlaySoundLoop(Sounds::SHOOTING);
	particles = new Particles(this->renderer);
	particles->Init();
	return true;
	
}

bool Gameloop::Input()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}

		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.scancode < 512)
			{
				keyDown[e.key.keysym.scancode] = true;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.scancode < 512)
			{
				keyDown[e.key.keysym.scancode] = true;
			}
		}
	}
		player->Input(keyDown);
		bullet->processInput(keyDown);
		return true;
	}

void Gameloop::Update()
{
	//process updating for game classes here
	//collision->Update();
	particles->Update();
	player->Update();
	bullet->update();
	enemy->update();
}

void Gameloop::Draw()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0,0,51, 255);
	if (score >= 5)
	{
		SDL_SetRenderDrawColor(renderer, 51, 51, 255, 255);
		if (score >= 10)
		{
			SDL_SetRenderDrawColor(renderer, 102, 153, 255, 255);
		}
	}
	//process drawing for game classes here
	Tiles->Draw();
	player->Draw();
	//collision->Draw();
	bullet->draw();
	enemy->draw();
	particles->Draw();
	textRenderer->RenderString(renderer, "", 1000, 0);
	textRenderer->RenderString(renderer, "", 1200, 0);
	textRenderer->RenderString(renderer, "", 400, 400);
	
	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void Gameloop::CleanUp() 
{
	//SAFERELEASE(textRenderer);
	//process clean up for game classes here
	player->CleanUp();
	bullet->clean();
	//enemy->clean();
	if (player)
	{
		delete player;
		player = nullptr;
	}
}
