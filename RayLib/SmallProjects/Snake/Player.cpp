#include "Player.h"
#include "raylib.h"
#include <string>

void Player::Spawn(Vector2 pos, int size)
{
	m_pos = pos;
	m_dir = { 1,0 };
	m_speed = 1;
	m_size = size;
}

void Player::Update(float time)
{
	Input();
	Move(time);
}

void Player::Draw()
{
	DrawRectangle(m_pos.x * m_size, m_pos.y * m_size, m_size, m_size, BLUE);
	if (m_tail) {
		m_tail->Draw(m_size);
	}
}

void Player::Move(float time)
{
	m_transition += time * m_speed;

	if (m_transition >= 1) {
		MoveTail();
		m_pos.x += m_dir.x;
		m_pos.y += m_dir.y;

		m_transition = 0;
	}
}

void Player::MoveTail()
{
	if (m_tail) {
		m_tail->MoveTo(m_pos);
	}
}

void Player::Input()
{
	if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && m_dir.y != 1)
		m_dir = { 0,-1 };
	else if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && m_dir.y != -1)
		m_dir = { 0,1 };
	else if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && m_dir.x != 1)
		m_dir = { -1,0 };
	else if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && m_dir.x != -1)
		m_dir = { 1,0 };

	if (IsKeyPressed(KEY_SPACE))
		AddTail();
}

void Player::Kill()
{
	if (m_tail)
		m_tail->Kill();
	m_tail = nullptr;
	m_length = 1;
}

bool Player::CollidedWithTail()
{
	if (m_tail)
		return m_tail->CollidedWith(m_pos);
	else
		return false;
}

void Player::AddTail()
{
	if (m_tail)
		m_tail->AddTail();
	else
		m_tail = new Tail();
	m_length++;
}
