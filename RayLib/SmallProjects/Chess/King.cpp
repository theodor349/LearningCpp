#include "King.h"


Vector2* King::Movements()
{
    Vector2* moves = new Vector2[8];
    moves[0] = { m_pos.x + 0, m_pos.y + 1 };
    moves[1] = { m_pos.x + 1, m_pos.y + 1 };
    moves[2] = { m_pos.x - 1, m_pos.y + 1 };
    moves[3] = { m_pos.x + 0, m_pos.y - 1 };
    moves[4] = { m_pos.x + 1, m_pos.y - 1 };
    moves[5] = { m_pos.x - 1, m_pos.y - 1 };
    moves[6] = { m_pos.x + 1, m_pos.y + 0 };
    moves[7] = { m_pos.x - 1, m_pos.y + 0 };
    return moves;
}

int King::GetMovementsSize()
{
    return 8;
}