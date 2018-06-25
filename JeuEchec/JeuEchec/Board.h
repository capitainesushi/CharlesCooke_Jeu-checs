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

	Case* GetCase(int i, int j) { return cases[i][j]; }
	
	vector<vector<Case*>> cases = vector<vector<Case*>>();
	const vector<vector<Case*>> GetCases() { return cases; }
	

protected:

private:
	SDL_Surface* ChessBoard;
	
	
};

