#include "Camera.h"

Camera::Camera()
{
	transform = std::make_shared<Transform>(sf::Vector2(0.0f, 0.0f), 0.0f, sf::Vector2(1.0f, 1.0f));
}

Camera::Camera(std::shared_ptr<sf::RenderWindow> _renderWindow )
	:
	renderWindow(_renderWindow)
{
	transform = std::make_shared<Transform>(sf::Vector2(0.0f, 0.0f), 0.0f, sf::Vector2(1.0f, 1.0f));
	
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view =sf::View(sf::FloatRect(pos.x, pos.y, size.x*scale.x, size.y * scale.y));
	renderWindow->setView(view);
}

Camera::Camera(std::shared_ptr<sf::RenderWindow> _renderWindow, std::shared_ptr<Transform> _transform)
	:
	renderWindow(_renderWindow),
	transform(_transform)
{
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = sf::View(sf::FloatRect(pos.x, pos.y, size.x * scale.x, size.y * scale.y));
	renderWindow->setView(view);
}

void Camera::SetRenderWindow(std::shared_ptr<sf::RenderWindow> renderWin)
{
	renderWindow = renderWin;
}

void Camera::Move(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		transform->Translate({ 0.0f,-moveSpeed * deltaTime });
		view.move({ 0.0f,-moveSpeed * deltaTime });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		transform->Translate({ 0.0f,+moveSpeed * deltaTime });
		view.move({ 0.0f,+moveSpeed * deltaTime });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		transform->Translate({ +moveSpeed * deltaTime,0.0f });
		view.move({ +moveSpeed * deltaTime,0.0f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		transform->Translate({ -moveSpeed * deltaTime,0.0f });
		view.move({ -moveSpeed * deltaTime,0.0f });
	}
	renderWindow->setView(view);
}
