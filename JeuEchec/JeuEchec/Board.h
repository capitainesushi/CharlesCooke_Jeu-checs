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
	vector<vector<Case*>> cases = vector<vector<Case*>>();

protected:

private:
	SDL_Surface* ChessBoard;
	
};

