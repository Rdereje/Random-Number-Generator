#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include "main.h"
const int S_Width = 1280;
const int S_Height = 720;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

bool init();
SDL_Texture* loadImage(std::string fname);
int close();
bool init()
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("SDL could load");
		return false;
	}
	
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	}
	
	
	gWindow = SDL_CreateWindow("Fidel Numbers", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_Width, S_Height, SDL_WINDOW_SHOWN );

	if(gWindow == nullptr)
	{
		printf("Window could not be created");
		return false;
	}
	
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == nullptr) {	
		std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return  false;
	}

	int imgFlags = IMG_INIT_PNG;
	int retFlags = IMG_Init(imgFlags);
	if(retFlags != imgFlags)
	{
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
		return false;
	}
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	return true;
}
int close()
{
	

	//~ SDL_DestroyRenderer(gRenderer);
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	return 0;
}

