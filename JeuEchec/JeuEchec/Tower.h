#pragma once
#include "Piece.h"

class Tower : public Piece
{
public:
	Tower(bool IsBlack);
	~Tower();

	std::string Tower::GetPieceType() { return IsWhite() ? "Blanc" : "Noir"; }

	 std::vector<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);
};

