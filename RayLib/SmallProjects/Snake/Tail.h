#pragma once
#include "raylib.h"

class Tail
{
public:
	void AddTail();
	void MoveTo(Vector2 pos);
	void Draw(int size);
	
	void Kill();
	bool CollidedWith(Vector2 pos);

protected:
	Tail* m_tail = nullptr;
	Vector2 m_pos = { -1, -1};
};

