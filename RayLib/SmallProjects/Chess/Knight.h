#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(bool isWhiteTeam) : Piece{ "Knight" } { m_isWhiteTeam = isWhiteTeam; }
	Vector2* Movements() override;
	int GetMovementsSize() override;
};

