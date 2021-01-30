#include "ChessWorld.h"
#include <string>

void ChessWorld::Init(int screenWidth, int screenHeight)
{
	int xSize = screenWidth / m_width;
	int ySize = screenHeight / m_height;
	m_size = xSize < ySize ? xSize : ySize;

	// Spawn Tiles
	SpawnTiles();
	// Spawn Peices 
	Piece* p = new Piece();
	p->SetSize(m_size);
	p->MoveTo({ 4,0 });
	m_pieces[0] = *p;
}

void ChessWorld::Update(float time)
{
 	if (IsKeyPressed(KEY_SPACE))
	{
		Piece* p = &m_pieces[0];
		Vector2* moves = p->Movements();
		p->MoveTo(moves[0]);
	}
}

void ChessWorld::Draw()
{
	// Tiles
	for (size_t x = 0; x < m_width; x++)
	{
		for (size_t y = 0; y < m_height; y++)
		{
			m_tiles[x * m_width + y].Draw();
		}
	}
	// Pieces
	m_pieces[0].Draw();
}

void ChessWorld::SpawnTiles()
{
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			Tile* tile = &m_tiles[x * m_width + y];
			tile->SetSize(m_size);
			tile->SetPos({ (float)x,(float)y });

			if (x % 2 == 0)
				tile->SetColor(y % 2 == 0);
			else 
				tile->SetColor(y % 2 != 0);
		}
	}
}
