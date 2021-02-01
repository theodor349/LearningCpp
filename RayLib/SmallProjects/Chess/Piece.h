#pragma once
#include "raylib.h"
#include <string>
#include "Tile.h"

class Piece
{
public:
	Piece(){}
	Piece(std::string name) { m_name = name; }

	void Draw();

	virtual void CalculateMoves(Tile* tiles);
	Vector2* Moves() { return m_moves; }
	int MoveCount() { return m_moveCount; }

	Vector2 GetPos() { return m_pos; }
	void MoveTo(Vector2 pos) { m_pos = pos; }
	bool IsWhiteTeam() { return m_isWhiteTeam; }
	void SetSize(int size) { m_size = size; }

protected:
	std::string m_name;

	Vector2* m_moves;
	int m_moveCount;
	void AddMove(Vector2 pos);

	Vector2 m_pos = { 0,0 };
	int m_size = 20;
	bool m_isWhiteTeam = false;
};

