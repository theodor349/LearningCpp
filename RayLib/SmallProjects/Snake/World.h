#pragma once
#include "Player.h"

class World
{
public:
	void Init(int screenWidth, int screenHeight);
	void Update(float time);
	void Draw();

protected:
	void SpawnPlayer();
	void SpawnFruite();
	void Physics();
	bool PlayerHitWall(Vector2 playerPos);

	Player* m_player;
	Vector2 m_fruitePos;
	int m_size = 20;
	int m_width;
	int m_height;
};

