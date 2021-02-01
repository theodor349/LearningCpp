#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(bool isWhiteTeam) : Piece{ "Pawn" } { m_isWhiteTeam = isWhiteTeam; }
	void CalculateMoves(Tile* tiles);
};
