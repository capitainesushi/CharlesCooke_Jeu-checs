/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Case.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
SDL_Rect gStringSurface;

Board* board;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
				gStringSurface = { 450,450,100,100 };

			}
		}
	}

	return success;
}

bool loadMedia()
{
	
	bool success = true;

	board = new Board();

	return success;
}

void close()
{
	delete board;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


SDL_Surface* loadSurface(std::string path)
{
	return IMG_Load(path.c_str());
}



int main(int argc, char* args[])
{
	

	


	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			
			SDL_Event e;
			Piece* piece;
			Case* cases;
			Board board;
			int x, y;
	
			while (!quit)
			{
		
				while (SDL_PollEvent(&e) != 0)
				{
	
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					if (e.type == SDL_MOUSEBUTTONDOWN)
					{			
						SDL_GetMouseState(&x, &y);
						std::cout << x / 125 << "  " << y / 125 << std::endl;					

						if (cases->piece)
						{

						}
					}

					if (e.type == SDL_MOUSEMOTION)
					{

					}

					if (e.type == SDL_MOUSEBUTTONUP)
					{

					}


				}

				//Apply the PNG image		
				board->Render(gScreenSurface);				

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	system("pause");
	//Free resources and close SDL
	close();

	return 0;
}