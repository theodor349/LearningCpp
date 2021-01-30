#pragma once
#include "raylib.h"

class Piece
{
public:
  	Vector2* Movements(Vector2 pos);
	int GetMovementsSize();

	Vector2* Attacks(Vector2 pos);
	int GetAttacksSize();

	bool IsWhiteTeam() { return m_isWhiteTeam; }

protected:
	bool m_isWhiteTeam = false;
};

