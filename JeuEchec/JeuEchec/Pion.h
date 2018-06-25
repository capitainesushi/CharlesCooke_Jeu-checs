#pragma once
#include "Piece.h"

class Pion : public Piece
{
public:
	Pion(bool IsBlack);
	~Pion();

	virtual std::vector<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);	
};

