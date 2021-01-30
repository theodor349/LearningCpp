#pragma once
#include "Tile.h"
#include "Piece.h"

class ChessWorld
{
public:
	void Init(int screenWidth, int screenHeight);
	void Update(float time);
	void Draw();

	void SpawnTiles();

protected:
	int m_width = 8;
	int m_height = 8;
	int m_size;

	Tile m_tiles[64];
	Piece m_pieces[32];
};

