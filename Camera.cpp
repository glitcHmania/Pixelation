#include "Camera.h"

Camera::Camera(sf::RenderWindow* _renderWindow)
	:
	renderWindow(_renderWindow)
{
	transform = std::make_shared<Transform>(sf::Vector2(0.0f, 0.0f), 0.0f, sf::Vector2(800.0f, 600.0f));
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();
	view = std::make_unique<sf::View>(sf::View(sf::FloatRect(pos.x, pos.y, scale.x, scale.y)));
	renderWindow->setView(*view.get());
}

Camera::Camera(sf::RenderWindow* _renderWindow, std::shared_ptr<Transform> _transform)
	:
	renderWindow(_renderWindow),
	transform(_transform)
{
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();
	view = std::make_unique<sf::View>(sf::View(sf::FloatRect(pos.x, pos.y, scale.x, scale.y)));
	renderWindow->setView(*view.get());
}

void Camera::Move(sf::Keyboard::Key pressedKey)
{
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();
	switch (pressedKey)
	{
	case sf::Keyboard::Key::W:
		pos.y -= 10.0f;
		break;
	case sf::Keyboard::Key::A:
		pos.x -= 10.0f;
		break;
	case sf::Keyboard::Key::S:
		pos.y += 10.0f;
		break;
	case sf::Keyboard::Key::D:
		pos.x += 10.0f;
		break;
	}
	transform->SetLocalPosition(pos);
	view.reset(new sf::View(sf::FloatRect(pos.x, pos.y, scale.x, scale.y)));
	renderWindow->setView(*view.get());
}
