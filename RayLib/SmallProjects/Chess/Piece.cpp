#include "Piece.h"

void Piece::Draw()
{
    DrawRectangle(m_pos.x * m_size, m_pos.y * m_size, m_size, m_size, GREEN);
}

Vector2* Piece::Movements()
{
    Vector2* res = new Vector2[1];
    res[0] = { m_pos.x, m_pos.y + 1 };
    return res;
}

int Piece::GetMovementsSize()
{
    return 1;
}
