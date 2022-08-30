#include "BSAttack.h"
#include "Animation.h"
BSAttack::BSAttack(IBoss* boss)
{
	m_Boss = boss;
}

void BSAttack::Init()
{
	m_Animation = new Animation(*DATA->getTexture("Boss1/boss_moveLeft"), sf::Vector2i(6, 1), 0.1f);
	m_ChangeTime = 2.f;
}

void BSAttack::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	m_currentTime += deltaTime;
	Animation* ani = (Animation*)m_Animation;
	//printf("%d\n", ani->getCurrentFrameCount());
	if (m_currentTime > m_ChangeTime) {
		sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
		pos.y += 60;
		m_Boss->getWeapon()->Fire(pos);
		m_Boss->changeNextState(STATE::JUMP);
	}
	if (m_Boss->getHitBox()->getPosition().x > 0) {
		m_Boss->getHitBox()->move(-100 * deltaTime, 0);
	}
	sf::Vector2f pos = m_Boss->getHitBox()->getPosition();
	pos.y += 27;
	m_Animation->setPosition(pos);
}

void BSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void BSAttack::Reset()
{
	m_Animation->Reset();
	m_currentTime = 0.f;
}
