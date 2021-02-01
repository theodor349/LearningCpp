#include "King.h"
#include "Tile.h"

void King::CalculateMoves(Tile tiles[64])
{
    delete[8] m_moves;
    m_moves = new Vector2[8];
    AddValidMove(tiles, { m_pos.x + 0, m_pos.y + 1 });
    AddValidMove(tiles, { m_pos.x + 1, m_pos.y + 1 });
    AddValidMove(tiles, { m_pos.x - 1, m_pos.y + 1 });
    AddValidMove(tiles, { m_pos.x + 0, m_pos.y - 1 });
    AddValidMove(tiles, { m_pos.x + 1, m_pos.y - 1 });
    AddValidMove(tiles, { m_pos.x - 1, m_pos.y - 1 });
    AddValidMove(tiles, { m_pos.x + 1, m_pos.y + 0 });
    AddValidMove(tiles, { m_pos.x - 1, m_pos.y + 0 });
}

void King::AddValidMove(Tile* tiles, Vector2 pos)
{
    int t = pos.x * 8 + pos.y;
    if (t < 64)
    {
        Piece** p = tiles[t].GetPeice();
        if (!p || (*p)->IsWhiteTeam() != m_isWhiteTeam)
            AddMove(pos);
    }
}
