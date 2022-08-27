#pragma once
#include <SDL_mixer.h>
#include <sstream>
#include <vector>

using namespace std;

enum Sounds {
	SHOOTING = 0,
	HIT,
	TOTAL_SOUNDS
};

class Sound {
public:
	Sound();
	virtual ~Sound();

	void PlaySound(int sound);
	void PlaySoundLoop(int sound);

private:
	Mix_Music * musicPlayer;
	vector<Mix_Chunk*> soundFiles;
};