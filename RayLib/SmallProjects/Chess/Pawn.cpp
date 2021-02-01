#include "Pawn.h"

void Pawn::CalculateMoves(Tile* tiles)
{
	m_moveCount = 0;
	m_moves = new Vector2[3];

	Vector2 pos = { m_pos.x, m_pos.y + (m_isWhiteTeam ? -1 : 1) };
	int t = pos.x * 8 + pos.y ;
	if (t < 64)
		if (!tiles[t].GetPeice())
			AddMove(pos);

	pos.x = m_pos.x + 1;
	t = pos.x * 8 + pos.y;
	if (t < 64)
		if ((*tiles[t].GetPeice())->IsWhiteTeam() != m_isWhiteTeam)
			AddMove(pos);

	pos.x = m_pos.x - 1;
	t = pos.x * 8 + pos.y;
	if (t < 64)
		if ((*tiles[t].GetPeice())->IsWhiteTeam() != m_isWhiteTeam)
			AddMove(pos);
}
