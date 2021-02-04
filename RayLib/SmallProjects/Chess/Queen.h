#pragma once
#include "Piece.h"
#include "Tile.h"

class Queen : public Piece
{
public:
	Queen(bool isWhiteTeam) : Piece{ "Qeen" } { m_isWhiteTeam = isWhiteTeam; }
	void CalculateMoves(Tile* tiles);
};

