
//https://shilohjames.wordpress.com/2014/04/27/tinyxml2-tutorial/#XML-CreateXMLDocument


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Board.h"
#include "Case.h"
#include "Piece.h"
#include "TinyXml2.h"

//Using les tinyxml2.cpp et .h
using namespace tinyxml2;
using namespace std;

//Afficher le code d'erreur. Utilisé dans les fonctionnalités XML
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

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

//Créé une variable qui vient de Board*
Board* board;

//Variables de Piece* et Case*
Piece* piece;
Case* lacase = nullptr;

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
		gWindow = SDL_CreateWindow("Charles et Jimmy decouvrent GIT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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


	// Load un Board à chaque partie
	board = new Board();

	return success;
}

void close()
{

	//Delete le pointeur
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

//Su
int XMLSave(vector<vector<Case*>> cases)
{
	//board->GetCase(x, y)->piece = lacase->piece;

	XMLDocument xmlDoc;
	XMLNode * pRoot = xmlDoc.NewElement("Root");
	xmlDoc.InsertFirstChild(pRoot);

	// premier élément création avec pointeur
	
	
	for (int i = 0; i < cases.size(); i++)
	{
		

		for (int j = 0; j < cases[i].size(); j++)
		{				
			
			XMLElement * pListElement = xmlDoc.NewElement("Case");
			pListElement->SetAttribute("positionX", cases[i][j]->GetRect()->x / 125);
			pListElement->SetAttribute("positionY", cases[i][j]->GetRect()->y / 125);
			
			if (cases[i][j]->piece != nullptr)
			{
				
				pListElement->SetText(cases[i][j]->piece->GetPieceType().c_str());
			}
			else
			{
				pListElement->SetText("null");
			}
			
			pRoot->InsertEndChild(pListElement);			
		}
	}

	XMLError returncode_savexml = xmlDoc.SaveFile("SavedData.xml");
	XMLCheckResult(returncode_savexml);	
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

			

			// Mes axes pour la souris
			int x, y;

			//Bool pour le tour par tour
			bool WhiteTurn = true;

			// Vecteur de vecteur qui sera associé à la fonction GetAvailableMove() plus bas
			std::vector<std::vector<int>> availablesMoves = std::vector<std::vector<int>>();

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
						//Get la position de la souris
						SDL_GetMouseState(&y, &x);
						std::cout << x / 125 << "  " << y / 125 << std::endl;

						//Associe lacase à la case appropriée (le 125 vient de 1000 / 8)
						lacase = board->GetCase(x / 125, y / 125);

						// Si j'ai clické sur une case avec une pièce
						if (lacase->piece != nullptr)
						{
							// Associé à la fonction GetAvailableMove
							availablesMoves = lacase->piece->GetAvailableMove(lacase->GetRect(), board->GetCases());
							if (!(WhiteTurn && lacase->piece->IsWhite()) &&
								!(!WhiteTurn && !lacase->piece->IsWhite()))
							{
								lacase = nullptr;
							}
						}
						else
						{
							// Change la case à nulle 
							lacase = nullptr;
						}
					}

					// à chaque détection de mouvement de la souris
					if (e.type == SDL_MOUSEMOTION)
					{
						if (lacase != nullptr)
						{
							SDL_GetMouseState(&x, &y);
							lacase->GetRect()->x = x - (125 / 2);
							lacase->GetRect()->y = y - (125 / 2);
						}
					}

					// Au relâchement du clic de souris
					if (e.type == SDL_MOUSEBUTTONUP)
					{
						if (lacase != nullptr && lacase->piece != nullptr)
						{			
							SDL_GetMouseState(&y, &x);

							// Si la position en I et J de GetCase est dans availablesMoves, entrer dans le if.
							for (int i = 0; i < availablesMoves.size(); i++)
							{
								int iDestination = availablesMoves[i][0];
								int jDestination = availablesMoves[i][1];

								int iPiece = x / 125;
								int jPiece = y / 125;

								// Y'a-t-il une pièce à la destination désirée?
								if (iDestination == iPiece && jDestination == jPiece)
								{
									
									// Dépose la pièce sur la nouvelle case
									board->GetCase(x / 125, y / 125)->piece = lacase->piece;

									// L'ancienne case devient nulle
									lacase->piece = nullptr;

									//Change de tour
									WhiteTurn = !WhiteTurn;
									
									XMLSave(board->GetCases());																	
								}
							}					

						}
						if (lacase != nullptr)
						{
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

		system("pause");
		//Free resources and close SDL
		close();
		

		return 0;
	}

}




