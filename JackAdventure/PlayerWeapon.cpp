//#include "PlayerWeapon.h"
//
//PlayerWeapon::PlayerWeapon()
//{
//	m_Num = 10;
//	m_currentTime = 0.f;
//}
//
//PlayerWeapon::~PlayerWeapon()
//{
//	for (auto it : m_ListBullet) {
//		if (it != nullptr) {
//			delete it;
//		}
//	}
//	m_ListBullet.clear();
//}
//
//void PlayerWeapon::Init(CollisionManager& collisionManager)
//{
//
//	for (int i = 0; i < m_Num; i++) {
//		Bullet* bullet = new Bullet();
//		bullet->Init();
//		bullet->getHitBox()->setAlive(false);
//		m_ListBullet.push_back(bullet);
//		collisionManager.addObj(bullet->getHitBox());
//
//	}
//}
//
//void PlayerWeapon::Update(float deltaTime)
//{
//	m_currentTime += deltaTime;
//	for (auto creep : m_ListBullet) {
//		creep->Update(deltaTime);
//	}
//}
//
//void PlayerWeapon::Render(sf::RenderWindow* window)
//{
//	for (auto creep : m_ListBullet) {
//		creep->Render(window);
//	}
//}
//
//void PlayerWeapon::Fire(sf::Vector2f startPoint)
//{
//	Bullet* bullet = nullptr;
//	for (auto it : m_ListBullet) {
//		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
//			bullet = it;
//			break;
//		}
//	}
//	if (bullet == nullptr) return;
//	bullet->getHitBox()->setAlive(true);
//	bullet->setStartPoint(startPoint);
//	bullet->Reset();
//}
