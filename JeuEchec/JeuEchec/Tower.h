#pragma once
#include "Piece.h"

class Tower : public Piece
{
public:
	Tower(bool IsBlack);
	~Tower();

	virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect);
};

