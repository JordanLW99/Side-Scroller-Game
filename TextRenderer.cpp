#include "TextRenderer.h"


TextRenderer::TextRenderer(string ttfFile, int fontSize)
{
	if (TTF_Init() < 0)
	{
		printf("TTF could not be initialised!", SDL_GetError());
	}

	font = TTF_OpenFont(ttfFile.c_str(), fontSize);
	if (font == NULL)
	{
		printf("Unable to load font %s\n", "comic.ttf", SDL_GetError());
	}

	comic = TTF_OpenFont("comic.ttf", 24); //this opens a font style and sets a size
}

TextRenderer::~TextRenderer()
{
	SDL_FreeSurface(textSurface);

}

void TextRenderer::RenderString(SDL_Renderer * renderer, string text, int x, int y)
{

	SDL_Color White = { 255,255,255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	char buff[100];
	sprintf_s(buff, "%d", score);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(comic, "S C O R E : ",  White);
	SDL_Surface* surfaceMessage1 = TTF_RenderText_Solid(comic, "H E A L T H : ", White);
	SDL_Surface* texttest = TTF_RenderText_Solid(comic, buff, White);// as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	//SDL_Surface* surfaceMessage1 = TTF_RenderText_Solid(comic1, " 0 ", White);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Texture* Message2 = SDL_CreateTextureFromSurface(renderer, surfaceMessage1);//now you can convert it into a texture
	SDL_Texture* Message1 = SDL_CreateTextureFromSurface(renderer, texttest);

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 500;  //controls the rect's x coordinate 
	Message_rect.y = 600; // controls the rect's y coordinte
	Message_rect.w = 175; // controls the width of the rect
	Message_rect.h = 100;

	SDL_Rect Message_rect1; //create a rect
	Message_rect1.x = 675;  //controls the rect's x coordinate 
	Message_rect1.y = 600; // controls the rect's y coordinte
	Message_rect1.w = 75; // controls the width of the rect
	Message_rect1.h = 100;

	SDL_Rect Message_rect2; //create a rect
	Message_rect2.x = 50;  //controls the rect's x coordinate 
	Message_rect2.y = 600; // controls the rect's y coordinte
	Message_rect2.w = 175; // controls the width of the rect
	Message_rect2.h = 100;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_RenderCopy(renderer, Message1, NULL, &Message_rect1);
	SDL_RenderCopy(renderer, Message2, NULL, &Message_rect2);

	//SDL_Color textColor = { 255,255,255 };
	//textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
	//SDL_Rect rect;
	//rect.x = x;
	//rect.y = y;
	//SDL_BlitSurface(textSurface, NULL, renderFrame, &rect);
}