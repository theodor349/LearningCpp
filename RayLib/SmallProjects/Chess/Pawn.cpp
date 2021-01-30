#include "Pawn.h"

Vector2* Pawn::Movements()
{
    Vector2* moves = new Vector2[1];
    moves[0] = { m_pos.x, m_pos.y + (m_isWhiteTeam ? -1 : 1) };
    return moves;
}

int Pawn::GetMovementsSize()
{
    return 1;
}
