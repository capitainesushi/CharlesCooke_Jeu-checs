#pragma once
#include "Piece.h"

class Pion : public Piece
{
public:
	Pion(bool IsBlack);
	~Pion();

	virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect);
	
};

