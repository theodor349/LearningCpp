#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(bool isWhiteTeam) : Piece{ "Bishop" } { m_isWhiteTeam = isWhiteTeam; }
	Vector2* Movements() override;
	int GetMovementsSize() override;
};

