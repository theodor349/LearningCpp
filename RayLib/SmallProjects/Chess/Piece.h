#pragma once
#include "raylib.h"
#include <string>

class Piece
{
public:
	Piece(){}
	Piece(std::string name) { m_name = name; }

	void Draw();

	virtual Vector2* Movements();
	virtual int GetMovementsSize();

	void MoveTo(Vector2 pos) 
	{ 
		std::printf("New Pos: %.0f, %0.f\n", pos.x, pos.y); 
		m_pos = pos; 
		std::printf("New Pos: %.0f, %0.f\n", m_pos.x, m_pos.y); 
	}
	bool IsWhiteTeam() { return m_isWhiteTeam; }
	void SetSize(int size) { m_size = size; }

protected:
	std::string m_name;
	Vector2 m_pos = { 0,0 };
	int m_size = 20;
	bool m_isWhiteTeam = false;
};

