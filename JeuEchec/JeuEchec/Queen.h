#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(bool IsBlack);
	~Queen();

	//virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect);
};

