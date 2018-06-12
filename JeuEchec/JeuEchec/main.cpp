/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

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

// Initialiser mon vecteur de vecteur:
vector<vector<SDL_Rect>> cases = vector<vector<SDL_Rect>>({ {}, {} });
// Initialiser les surfaces pour les pièces
vector<vector<SDL_Surface*>> pieces = vector<vector<SDL_Surface*>>({ {}, {} });



//P.Push_back(new vector<SDL_Rect>);
//for(j = 0; 

//Current displayed PNG image
SDL_Surface* ChessBoard = NULL;
SDL_Surface* King = NULL;
SDL_Surface* Queen = NULL;
SDL_Surface* Fou = NULL;
SDL_Surface* Knight = NULL;
SDL_Surface* Tower = NULL;
SDL_Surface* Pion = NULL;



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

	Pion = loadSurface("Images/chess/Pion.png");
	if (Pion == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	Knight = loadSurface("Images/chess/Knight.png");
	if (Knight == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	Tower = loadSurface("Images/chess/Tower.png");
	if (Tower == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	Fou = loadSurface("Images/chess/Fou.png");
	if (Fou == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	Queen = loadSurface("Images/chess/Queen.png");
	if (Queen == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}
	
	King = loadSurface("Images/chess/King.png");
	if (King == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	//Load PNG surface
	ChessBoard = loadSurface("Images/chess/ChessBoard.bmp");
	if (ChessBoard == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface(ChessBoard);
	ChessBoard = NULL;

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
	int x = 0;
	int y = 0;

	// Crée les rectangles dans le chessboard:
	for (int i = 0; i < 8; i++)
	{		
		cases.push_back(vector<SDL_Rect>());
		for(int j = 0; j < 8; j++)
		{
			cases[i].push_back({ j * 125, i * 125, 125, 125 });			
		}
	}
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

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Apply the PNG image
				SDL_BlitSurface(ChessBoard, NULL, gScreenSurface, NULL);

				SDL_BlitSurface(Tower, NULL, gScreenSurface, &cases[0][0]);
				SDL_BlitSurface(Knight, NULL, gScreenSurface, &cases[0][1]);
				SDL_BlitSurface(Fou, NULL, gScreenSurface, &cases[0][2]);
				SDL_BlitSurface(Queen, NULL, gScreenSurface, &cases[0][3]);
				SDL_BlitSurface(King, NULL, gScreenSurface, &cases[0][4]);			
				SDL_BlitSurface(Fou, NULL, gScreenSurface, &cases[0][5]);
				SDL_BlitSurface(Pion, NULL, gScreenSurface, &cases[1][0]);

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