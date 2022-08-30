#include "GSPlay.h"
#include "../GameManager/ResourceManager.h"
GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{

	printf("Play game");
	//m_Background.Init();
	sf::Texture* texture = DATA->getTexture("Background layers/Background");
	sf::Vector2i m_SizeImage = (sf::Vector2i)texture->getSize();
	m_background.setTexture(*texture);
	m_background.setPosition(sf::Vector2f(screenWidth / 2, screenHeight - m_SizeImage.y / 2));
	m_background.setOrigin((sf::Vector2f)m_SizeImage * 0.5f);
//	layer = new Layer();
	//mInit(path + "Layer_0009_2", 50);
	//m_background.push_back(layer);

	m_Player.Init();
	m_Boss.Init(m_CollisionManager);
	m_CollisionManager.addObj(m_Player.getHitBox());
	m_CreepManager.Init(m_CollisionManager);

	m_Score.setFont(*DATA->getFont("ARCADE"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::White);
	m_Score.setPosition(50,50);

	DATA->playMusic("Uprising");
	DATA->getMusic("Uprising")->setLoop(true);;
	DATA->getMusic("Uprising")->setVolume(30);
}

void GSPlay::Update(float deltaTime)
{
	if (m_Player.getHitBox()->isAlive()) {
		m_currentTime += deltaTime;
		if (m_currentTime >= 0.5f) {
			m_currentScore++;
			m_Score.setString(std::to_string(m_currentScore));
			m_currentTime -= 1.f;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(m_currentScore);

	//if (m_Player.getHitBox()->isAlive()) m_Background.Update(deltaTime);
	m_Player.Update(deltaTime);
	if (m_Player.getHitBox()->isAlive()) {
		m_Boss.Update(deltaTime);
		m_CreepManager.Update(deltaTime);
		m_CollisionManager.Update();
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	//m_Background.Render(window);
	window->draw(m_background);
	m_Boss.Render(window);
	m_Player.Render(window);
	m_CreepManager.Render(window);
	window->draw(m_Score);

}
