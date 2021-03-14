#include "Enemy.h"



Enemy::Enemy()
{
	m_Renderer = Renderer2D::getInstance();
	m_Resources = Resources::getInstance();
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Move();
}

void Enemy::Render()
{
		//init Sprite
}

void Enemy::Move()
{

}
