#pragma once
#include "Piece.h"
#include "Tile.h"

class Bishop : public Piece
{
public:
	Bishop(bool isWhiteTeam) : Piece{ "Bishop" } { m_isWhiteTeam = isWhiteTeam; }
	void CalculateMoves(Tile* tiles);
};

