#pragma once
#include "Piece.h"

class Tower : public Piece
{
public:
	Tower(bool IsBlack);
	~Tower();

	virtual std::vector<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);
};

