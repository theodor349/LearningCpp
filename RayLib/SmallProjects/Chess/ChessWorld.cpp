#include "ChessWorld.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
#include <string>

void ChessWorld::Init(int screenWidth, int screenHeight)
{
	int xSize = screenWidth / m_width;
	int ySize = screenHeight / m_height;
	m_size = xSize < ySize ? xSize : ySize;

	// Spawn Tiles
	SpawnTiles();
	// Spawn Peices 
	SpawnPieces();
}

void ChessWorld::Update(float time)
{
	if (IsMouseButtonPressed(MouseButton::MOUSE_LEFT_BUTTON))
	{
		auto tile = GetTileUnderMouse();
		if (m_selectedPiece != nullptr)
		{
			auto tilePos = tile->GetPos();
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
			if (tile->GetPeice())
			{
				m_selectedPiece = tile->GetPeice();
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

void ChessWorld::SpawnPieces()
{
	int i = 0;
	//// White
	float pawnRow = (m_height - 2);
	float backRow = (m_height - 1);
	bool isWhite = true;
	SpawnTeam(&i, backRow, pawnRow, isWhite);

	//// Black
	pawnRow = 1;
	backRow = 0;
	isWhite = false;
	SpawnTeam(&i, backRow, pawnRow, isWhite);
}

void ChessWorld::SpawnTeam(int* i, float backRow, float pawnRow, bool isWhite)
{
	Piece* p = nullptr;
	// Pawns
	for (size_t x = 0; x < m_width; x++)
	{
		p = new Pawn(isWhite);
		SetupPiece(i, p, { (float)x, pawnRow });
	}
	p = new King(isWhite);
	SetupPiece(i, p, { 4,backRow });
	p = new Queen(isWhite);
	SetupPiece(i, p, { 3,backRow });
	p = new Rook(isWhite);
	SetupPiece(i, p, { 0,backRow });
	p = new Rook(isWhite);
	SetupPiece(i, p, { 7,backRow });
	p = new Knight(isWhite);
	SetupPiece(i, p, { 1,backRow });
	p = new Knight(isWhite);
	SetupPiece(i, p, { 6,backRow });
	p = new Bishop(isWhite);
	SetupPiece(i, p, { 2,backRow });
	p = new Bishop(isWhite);
	SetupPiece(i, p, { 5,backRow });
}

void ChessWorld::SetupPiece(int* i, Piece* p, Vector2 pos)
{
	p->SetSize(m_size);
	MovePiece(pos, p);
	m_pieces[*i] = p;
	*i += 1;
}

void ChessWorld::MovePiece(Vector2 pos, Piece* p)
{
	p->MoveTo(pos);
	m_tiles[(int)(pos.x * m_width + pos.y)].AssignPeice(p);
}

Tile* ChessWorld::GetTileUnderMouse()
{
	auto mousePos = GetMousePosition();
	int x = mousePos.x / m_size;
	int y = mousePos.y / m_size;
	return &m_tiles[x * m_width + y];
}
