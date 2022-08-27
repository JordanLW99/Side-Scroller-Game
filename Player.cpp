#include "Player.h"


int score = 0;
//extern Gameloop* GameLoop;
#define MAP_SIZE_X 16
#define MAP_SIZE_Y 8
#define MAP_TILE_SIZE_PX 96
extern int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X];

Player::Player(SDL_Renderer * renderer)
{
	this->renderer = renderer;
	this->position.x = 100;
	this->position.y = 465;
	this->position.w = 128;
	this->position.h = 128;
	//boundingSphere = new Sphere(position.x + (position.w / 2),
		//position.y + (position.h / 2), position.w / 2);

	this->random.x = -33;
	this->random.y = 448;
	this->random.w = 128;
	this->random.h = 128;
}

Player::~Player()
{
}

void Player::Initialise()
{
	SDL_Surface * surface = IMG_Load("./GameObjects/Player.png");
	SDL_Surface * surface1 = IMG_Load("./GameObjects/Block2.png");
	this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
	this->texture1 = SDL_CreateTextureFromSurface(this->renderer, surface1);
	SDL_FreeSurface(surface);
	SDL_FreeSurface(surface1);

	//sound = new Sound();
	//this->position.x = 0;
	//position.y = 560;
	//position.w = 128;
	//position.h = 128;
}

bool Player::Input(bool * keyDown)
{
	/*const Uint8 *keys = SDL_GetKeyboardState(NULL);
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			break;
		}
		if (keys[SDL_SCANCODE_RIGHT]) {
			this->position.x += 10;
		}
		if (keys[SDL_SCANCODE_LEFT]) {
			this->position.x -= 10;
		}
	}*/

	/*if (keyDown[SDL_SCANCODE_RIGHT]) {
		this->position.x += 2;
	}

	if (keyUp[SDL_SCANCODE_RIGHT]) {
		this->position.x -= 0;
	}*/
	return true;
}

bool Player::Update()
{
	SDL_Rect playerRect = {this->position.x,525, 32, 32 };
	SDL_Rect tileRect = {  325, 525,32,32};
	SDL_Rect nullRect;

	if (score >= 1)
	{
		MAP_DATA[0][2] = -1;
		MAP_DATA[5][2] = 4;
		if (score >= 2)
		{
			MAP_DATA[0][3] = -1;
			MAP_DATA[5][3] = 4;
		}
	}


	{
		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_RIGHT]) {
			this->position.x += 5;
		}
		if (keys[SDL_SCANCODE_LEFT]) {
			this->position.x -= 5;
		}
		SDL_Rect testRect = { this->random.x, 465 ,96, 64 };

		if (SDL_IntersectRect(&playerRect, &testRect, &nullRect)) {
			position.x = this->random.x + 100;
		}

		/*if (keys[SDL_SCANCODE_UP]) {
			this->position.y -= 5;
			//sound->PlaySound(Sounds::SHOOTING);
		}
		if (keys[SDL_SCANCODE_DOWN]) {
			this->position.y += 5;
			//sound->PlaySound(Sounds::SHOOTING);
		}*/
		/*SDL_Event e;

		enum KeyStates {
			LEFT = 0,
			RIGHT,
			KEYSTATES_COUNT
		};
		bool keyStates[KeyStates::KEYSTATES_COUNT];

		//[9] implement a loop to check all SDL events
		while (SDL_PollEvent(&e) != 0) {

			//[10] Handle the X button at top right
			//of the window
			if (e.type == SDL_QUIT) {
				return false;
			}

			//[11] Detect keydown events
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					keyStates[LEFT] = true;
					break;
				case SDLK_RIGHT:
					keyStates[RIGHT] = true;
					break;
				}
			}

			//[12] Detect key up events
			if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					keyStates[LEFT] = false;
					break;
				case SDLK_RIGHT:
					keyStates[RIGHT] = false;
					break;
				}
			}
		}*/
		return true;
	}
}

void Player::Draw()
{
	SDL_Rect r = { this->position.x, this->position.y, this->position.h, this->position.w };
	SDL_Rect rand = { this->random.x, this->random.y, this->random.w, this->random.h };
	SDL_RenderCopy(this->renderer, this->texture, 0, &r);
	SDL_RenderCopy(this->renderer, this->texture1, 0, &rand);
}
void Player::CleanUp()
{
	SDL_DestroyTexture(this->texture);
}