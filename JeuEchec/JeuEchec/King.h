#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(bool IsBlack);
	~King();

	std::string King::GetPieceType() { return IsWhite() ? "Blanc" : "Noir"; }

	std::vector<std::vector<int>> King::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);
};

