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
			if (!tile->GetPeice() || !((*tile->GetPeice())->IsWhiteTeam() == (*m_selectedPiece)->IsWhiteTeam()))
			{
				auto tilePos = tile->GetPos();
				auto moves = (*m_selectedPiece)->Moves();
				int count = (*m_selectedPiece)->MoveCount();
				for (size_t i = 0; i < count; i++)
				{
					Vector2 pos = moves[i];
					if (pos.x == tilePos.x && pos.y == tilePos.y)
					{
						MovePiece(pos, m_selectedPiece);
						m_selectedPiece = nullptr;
						break;
					}
				}
			}
		}
		else
		{
			if (tile->GetPeice())
			{
				m_selectedPiece = tile->GetPeice();
				(*m_selectedPiece)->CalculateMoves(m_tiles);
			}
		}
	}
	else if (IsMouseButtonPressed(MouseButton::MOUSE_RIGHT_BUTTON))
	{
		m_selectedPiece = nullptr;
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

	if (m_selectedPiece)
	{
		auto move = (*m_selectedPiece)->Moves();
		int count = (*m_selectedPiece)->MoveCount();
		for (size_t i = 0; i < count; i++)
		{
			if (GetTileAt(move[i])->GetPeice())
				DrawHightLight(move[i], RED);
			else
				DrawHightLight(move[i], BLUE);
		}
	}
}

void ChessWorld::DrawHightLight(Vector2 pos, Color c) 
{
	int size = m_size / 3;
	int offset = (m_size - size) / 2;
	DrawRectangle(pos.x * m_size + offset, pos.y * m_size + offset, size, size, c);
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
	m_pieces[*i] = p;
	MovePiece(pos, &m_pieces[*i]);
	*i += 1;
}

void ChessWorld::MovePiece(Vector2 pos, Piece** p)
{
	auto oldTile = &m_tiles[(int)((*p)->GetPos().x * m_width + (*p)->GetPos().y)];
	oldTile->RemovePiece();

	auto t = &m_tiles[(int)(pos.x * m_width + pos.y)];
	(*p)->MoveTo(pos);
	t->AssignPeice(p);
}

Tile* ChessWorld::GetTileUnderMouse()
{
	auto mousePos = GetMousePosition();
	int x = mousePos.x / m_size;
	int y = mousePos.y / m_size;
	return &m_tiles[x * m_width + y];
}
