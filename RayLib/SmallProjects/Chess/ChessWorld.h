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
	void MovePiece(Vector2 pos, Piece* p);

	int m_width = 8;
	int m_height = 8;
	int m_size;

	Tile m_tiles[64];
	Piece* m_pieces[32];
	Piece* m_selectedPiece = nullptr;
};

