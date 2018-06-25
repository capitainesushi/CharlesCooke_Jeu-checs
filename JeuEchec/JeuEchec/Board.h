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
	const vector<vector<Case*>> GetCases() { return cases; }
	

protected:

private:
	SDL_Surface* ChessBoard;
	vector<vector<Case*>> cases = vector<vector<Case*>>();
};

