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
#include "Piece.h"

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
			Case* lacase = nullptr;
			
			int x, y;
			bool WhiteTurn = true;
	
			std::list<std::vector<int>> availablesMoves = std::list<std::vector<int>>();

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

						SDL_GetMouseState(&y, &x);
						std::cout << x / 125 << "  " << y / 125 << std::endl;
						
						lacase = board->GetCase(x / 125, y / 125);

						if (lacase->piece != nullptr)
						{
							availablesMoves = lacase->piece->GetAvailableMove(lacase->GetRect());
							if (!(WhiteTurn && lacase->piece->IsWhite()) && 
								!(!WhiteTurn && !lacase->piece->IsWhite()))
							{
								lacase = nullptr;
							}

							
						}
						else
						{
							lacase = nullptr;

						}
					}

					if (e.type == SDL_MOUSEMOTION)
					{
						if (lacase != nullptr)
						{
							SDL_GetMouseState(&x, &y);
							lacase->GetRect()->x = x - (125 / 2);
							lacase->GetRect()->y = y - (125 / 2);
						}
					}

					if (e.type == SDL_MOUSEBUTTONUP)
					{
						if (lacase != nullptr && lacase->piece != nullptr)
						{
							SDL_GetMouseState(&y, &x);

							// Si la position en I et J de GetCase est dans availablesMoves, entrer dans le if.
							if(board->GetCase(x / 125, y / 125)->piece == nullptr)
							{
								board->GetCase(x / 125, y / 125)->piece = lacase->piece;
								lacase->piece = nullptr;

								WhiteTurn = !WhiteTurn;
							}
							
							lacase->Reset();
							lacase = nullptr;
						}
												
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