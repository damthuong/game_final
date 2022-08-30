#include "BSJump.h"

BSJump::BSJump(IBoss* boss)
{
	m_Boss = boss;
}

void BSJump::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Boss1/boss_moveRight"), sf::Vector2i(6, 1), 0.1f);
	m_ChangeTime = 2.f;
	m_currentTime = 0.f;
}

void BSJump::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	Animation* ani = (Animation*)m_Animation;
	
	
	if (m_currentTime > m_ChangeTime) {
		/*int luckyState = rand() % 2;
		switch (luckyState)
		{
		case 0:
			m_Boss->changeNextState(STATE::ATTACK);
			break;
		case 1:
			m_Boss->changeNextState(STATE::JUMP);
			break;
		default:
			break;
		}*/
		m_Boss->changeNextState(STATE::ATTACK);
	}
	if (m_Boss->getHitBox()->getPosition().x < 300) {
		m_Boss->getHitBox()->move(200 * deltaTime, 0);
	}

	m_Animation->setPosition(m_Boss->getHitBox()->getPosition());
}

void BSJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSJump::Reset()
{	m_Animation->Reset();
	m_currentTime = 0.f;
}
