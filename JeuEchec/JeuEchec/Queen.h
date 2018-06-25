#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(bool IsBlack);
	~Queen();

	std::vector<std::vector<int>> Queen::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);
};

