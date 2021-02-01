#pragma once
#include "Piece.h"

class Tile
{
public:
	void Draw();
	void SetPos(Vector2 pos) { m_pos = pos; }
	void SetColor(bool isDark) { m_isDark = isDark; }
	void SetSize(int size) { m_size = size; }

	void AssignPeice(Piece** p);
	Piece** GetPeice() { return m_piece; }
	void RemovePiece() { m_piece = NULL; }
	Vector2 GetPos() { return m_pos; }

protected:
	Piece** m_piece;
	bool m_isDark;
	int m_size;
	Vector2 m_pos;
};

