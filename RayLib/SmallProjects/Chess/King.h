#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(bool isWhiteTeam) : Piece { "King" }{ m_isWhiteTeam = isWhiteTeam; }
	Vector2* Movements() override;
	int GetMovementsSize() override;
};

