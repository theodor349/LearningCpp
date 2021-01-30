#include "World.h"
#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <string>

void World::Init(int screenWidth, int screenHeight)
{
	srand(time(0));

	m_width = screenWidth / m_size;
	m_height = screenHeight/ m_size;

	m_player = new Player();
	SpawnPlayer();

	SpawnFruite();
}

void World::Update(float time)
{
	m_player->Update(time);
	Physics();
}

void World::Draw()
{
	m_player->Draw();

	DrawRectangle(m_fruitePos.x * m_size, m_fruitePos.y * m_size, m_size, m_size, GREEN);

	std::string s = "Length: " + std::to_string(m_player->GetLength());
	char const* lengthText = s.c_str();
	DrawText(lengthText, 10, 10, 20, GRAY);
}

void World::SpawnPlayer()
{
	m_player->Spawn({ ((float)(int)(m_width / 2)),((float)(int)(m_height / 2)) }, m_size);
}

void World::SpawnFruite()
{
	m_fruitePos = { (float)(rand() % m_width), (float)(rand() % m_height) };
}

void World::Physics()
{
	auto playerPos = m_player->GetPos();
	if (playerPos.x == m_fruitePos.x && playerPos.y == m_fruitePos.y) 
	{
		m_player->AddTail();
		SpawnFruite();
	}
	if (m_player->CollidedWithTail() || PlayerHitWall(playerPos)) 
	{
		m_player->Kill();
		SpawnPlayer();
	}
}

bool World::PlayerHitWall(Vector2 playerPos)
{
	return playerPos.x < 0 || playerPos.x > m_width
		|| playerPos.y < 0 || playerPos.y > m_height;
}
