#pragma once
#include "Piece.h"
#include "Tile.h"

class Knight : public Piece
{
public:
	Knight(bool isWhiteTeam) : Piece{ "Knight" } { m_isWhiteTeam = isWhiteTeam; }
	void CalculateMoves(Tile* tiles);
};

