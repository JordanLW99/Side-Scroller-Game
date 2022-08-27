#include "Gameloop.h"
#include "MeteorManager.h"

#undef main

//this can be accessed in any cpp file by adding "extern GameLoop * gameLoop"
Gameloop * GameLoop;
MeteorManager * enemy;

int main(int argc, char* args[])
{
	//construct a new gameloop object
	GameLoop = new Gameloop();
	if (!GameLoop->Initialise()) {
		return 1;
	}

	//update and draw the game until quit by the user
	while (GameLoop->Input()) {
		GameLoop->Update();
		GameLoop->Draw();
	}

	//perform any necessary cleaning up
	GameLoop->CleanUp();

	//delete the gameloop object which has been allocated to memory.
	delete GameLoop;
	return 0;
}