#pragma once
#include <SDL.h>
#include <vector>

using namespace std;

class Case;

class Board
{
public:
	Board();
	~Board();
	void Render(SDL_Surface* gScreenSurface);

	Case* GetCase(int i, int j)
	{
		return cases[i][j];
	}
	
	

protected:

private:
	SDL_Surface* ChessBoard;
	vector<vector<Case*>> cases = vector<vector<Case*>>();
};

