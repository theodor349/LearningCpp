#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(bool isWhiteTeam) : Piece{ "Qeen" } { m_isWhiteTeam = isWhiteTeam; }
	Vector2* Movements() override;
	int GetMovementsSize() override;
};

