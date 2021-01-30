#pragma once
#include "raylib.h"

class Piece
{
public:
	void Draw();

	Vector2* Movements();
	int GetMovementsSize();
	void MoveTo(Vector2 pos) { m_pos = pos; }

	bool IsWhiteTeam() { return m_isWhiteTeam; }
	void SetSize(int size) { m_size = size; }

protected:
	Vector2 m_pos;
	int m_size;
	bool m_isWhiteTeam = false;
};

