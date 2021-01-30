#pragma once

#include "raylib.h"
#include "Tail.h"

class Player
{
public:
	void Spawn(Vector2 pos, int size);
	void Update(float time);
	void Draw();
	
	void Kill();
	bool CollidedWithTail();
	void AddTail();
	Vector2 GetPos() { return m_pos; }
	int GetLength() { return m_length; }

protected:
	Vector2 m_pos;
	Vector2 m_dir;
	float m_speed;
	float m_transition = 0;
	int m_size;
	Tail* m_tail = nullptr;
	int m_length = 1;

	void Move(float time);
	void MoveTail();
	void Input();
};

