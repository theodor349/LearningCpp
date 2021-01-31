#include "Tile.h"
#include <string>

void Tile::Draw()
{
	DrawRectangle(m_pos.x * m_size, m_pos.y * m_size, m_size, m_size, m_isDark ? BLACK : GRAY);
}

void Tile::AssignPeice(Piece** p)
{
	if (m_piece)
	{
		delete* m_piece;
		*m_piece = nullptr;
	}
	m_piece = p;
}

