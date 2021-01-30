#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King() : Piece { "King" }{}
	Vector2* Movements() override;
	int GetMovementsSize() override;
};

