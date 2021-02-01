#include "Piece.h"

void Piece::Draw()
{
    DrawText(m_name.c_str(), m_pos.x * m_size, m_pos.y * m_size, 20, m_isWhiteTeam ? WHITE : RED);
}

void Piece::CalculateMoves(Tile* tiles)
{
}

void Piece::AddMove(Vector2 pos)
{
    m_moves[m_moveCount] = pos;
    m_moveCount++;
}
