#pragma once
#include "Piece.h"

class Fou : public Piece
{
public:
	Fou(bool IsBlack);
	~Fou();

	//virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect);
};

