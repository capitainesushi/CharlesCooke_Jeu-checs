#pragma once
#include "Piece.h"

class Fou : public Piece
{
public:
	Fou(bool IsBlack);
	~Fou();

	std::vector<std::vector<int>> Fou::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);
	
};

