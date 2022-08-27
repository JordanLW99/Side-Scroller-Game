#pragma once
#include <SDL_ttf.h>
#include <string>
#include "MeteorManager.h"
#include "Player.h"

using namespace std;

class TextRenderer
{
public:
	TextRenderer(string ttfFile, int fontSize);
	virtual ~TextRenderer();
	void RenderString(SDL_Renderer * renderer, string text, int x, int y);

private:
	SDL_Surface * textSurface;
	TTF_Font * font;
	TTF_Font* comic;
	//MeteorManager * mm;
	//int score = 100;
};
