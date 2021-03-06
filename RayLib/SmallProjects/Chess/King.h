#pragma once
#include "Piece.h"
#include "Tile.h"

class King : public Piece
{
public:
	King(bool isWhiteTeam) : Piece { "King" }{ m_isWhiteTeam = isWhiteTeam; }
	void CalculateMoves(Tile* tiles) override;

protected:
	void AddValidMove(Tile* tiles, Vector2 pos);
};

