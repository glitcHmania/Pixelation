#include "Camera.h"

Camera::Camera(sf::RenderWindow* _renderWindow )
	:
	renderWindow(_renderWindow)
{
	transform = std::make_shared<Transform>(sf::Vector2(0.0f, 0.0f), 0.0f, sf::Vector2(1.0f, 1.0f));
	
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = std::make_unique<sf::View>(sf::View(sf::FloatRect(pos.x, pos.y, size.x*scale.x, size.y * scale.y)));
	renderWindow->setView(*view.get());
}

Camera::Camera(sf::RenderWindow* _renderWindow, std::shared_ptr<Transform> _transform)
	:
	renderWindow(_renderWindow),
	transform(_transform)
{
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = std::make_unique<sf::View>(sf::View(sf::FloatRect(pos.x, pos.y, size.x * scale.x, size.y * scale.y)));
	renderWindow->setView(*view.get());
}

void Camera::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		transform->Translate({ 0.0f,-0.1f });
		view->move({ 0.0f,-0.1f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		transform->Translate({ 0.0f,+0.1f });
		view->move({ 0.0f,+0.1f });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		transform->Translate({ +0.1f,0.0f });
		view->move({ +0.1f,0.0f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		transform->Translate({ -0.1f,0.0f });
		view->move({ -0.1f,0.0f });
	}
	renderWindow->setView(*view.get());
}
