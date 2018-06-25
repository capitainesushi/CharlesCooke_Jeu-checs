#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(bool IsBlack);
	~Knight();

	std::string Knight::GetPieceType() { return IsWhite() ? "Blanc" : "Noir"; }

	std::vector<std::vector<int>> Knight::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases);
};

