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
}

void ChessWorld::Update(float time)
{

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
