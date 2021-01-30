#include "Tail.h"

void Tail::AddTail()
{
	if (m_tail)
		m_tail->AddTail();
	else 
		m_tail = new Tail();
}

void Tail::MoveTo(Vector2 pos)
{
	if (m_tail) {
		m_tail->MoveTo(m_pos);
	}

	m_pos = pos;
}

void Tail::Draw(int size) {
	if (m_tail) {
		m_tail->Draw(size);
	}

	DrawRectangle(m_pos.x * size, m_pos.y * size, size, size, BLUE);
}

void Tail::Kill()
{
	if (m_tail)
		m_tail->Kill();
	m_tail = nullptr;
}

bool Tail::CollidedWith(Vector2 pos)
{
	if (pos.x == m_pos.x && pos.y == m_pos.y)
		return true;

	if (m_tail)
		return m_tail->CollidedWith(pos);
	else
		return false;
}
