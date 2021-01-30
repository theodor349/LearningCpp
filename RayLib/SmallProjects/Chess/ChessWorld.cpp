#include "ChessWorld.h"
#include "King.h"
#include <string>

void ChessWorld::Init(int screenWidth, int screenHeight)
{
	int xSize = screenWidth / m_width;
	int ySize = screenHeight / m_height;
	m_size = xSize < ySize ? xSize : ySize;

	// Spawn Tiles
	SpawnTiles();
	// Spawn Peices 
	Piece* p = new King();
	p->SetSize(m_size);
	MovePiece({ 4,0 }, p);
	m_pieces[0] = p;
}

void ChessWorld::Update(float time)
{
	if (IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		auto mousePos = GetMousePosition();
		int x = mousePos.x / m_size;
		int y = mousePos.y / m_size;
		Tile tile = m_tiles[x * m_width + y];
		if (m_selectedPiece != nullptr)
		{
			auto tilePos = tile.GetPos();
			auto moves = m_selectedPiece->Movements();
			int count = m_selectedPiece->GetMovementsSize();
			for (size_t i = 0; i < count; i++)
			{
				Vector2 pos = moves[i];
				if (pos.x == tilePos.x && pos.y == tilePos.y)
				{
					MovePiece(pos, m_selectedPiece);
					m_selectedPiece = nullptr;
				}
			}
		}
		else
		{
			if (tile.GetPeice())
			{
				m_selectedPiece = tile.GetPeice();
			}
		}
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
	for (size_t i = 0; i < 32; i++)
	{
		if(m_pieces[i])
			m_pieces[i]->Draw();
	}
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

void ChessWorld::MovePiece(Vector2 pos, Piece* p)
{
	p->MoveTo(pos);
	m_tiles[(int)(pos.x * m_width + pos.y)].AssignPeice(p);
}
