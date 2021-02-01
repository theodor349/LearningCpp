#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(bool isWhiteTeam) : Piece{ "Rook" } { m_isWhiteTeam = isWhiteTeam; }	
	void CalculateMoves(Tile* tiles);
};

