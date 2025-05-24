#include "Camera.h"
#include "EventDispatcher.h"
#include "Events.h"
#include "ObjectManager.h"

Camera::Camera()
	:
	renderWindow(nullptr)
{
	transform = std::make_shared<Transform>(sf::Vector2(0.0f, 0.0f), 0.0f, sf::Vector2(1.0f, 1.0f));
}

Camera::Camera(sf::RenderWindow& _renderWindow)
	:
	renderWindow(&_renderWindow)
{
	transform = std::make_shared<Transform>(sf::Vector2(0.0f, 0.0f), 0.0f, sf::Vector2(1.0f, 1.0f));
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = sf::View(sf::FloatRect(pos.x, pos.y, size.x * scale.x, size.y * scale.y));
	renderWindow->setView(view);
}

Camera::Camera(sf::RenderWindow& _renderWindow, std::shared_ptr<Transform> _transform)
	:
	renderWindow(&_renderWindow),
	transform(_transform)
{
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = sf::View(sf::FloatRect(pos.x, pos.y, size.x * scale.x, size.y * scale.y));
	renderWindow->setView(view);
}

Camera::Camera(sf::RenderWindow& _renderWindow, Transform _transform)
	:
	renderWindow(&_renderWindow)
{
	transform = std::make_shared<Transform>(
		_transform.GetLocalPosition(),
		_transform.GetLocalRotation(),
		_transform.GetLocalScale()
);
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = sf::View(sf::FloatRect(pos.x, pos.y, size.x * scale.x, size.y * scale.y));
	renderWindow->setView(view);
}

void Camera::SetRenderWindow(sf::RenderWindow& renderWin)
{
	renderWindow = &renderWin;
}

void Camera::ResizeWindow()
{
	sf::Vector2 size = renderWindow->getSize();
	sf::Vector2 pos = transform->GetLocalPosition();
	sf::Vector2 scale = transform->GetLocalScale();

	view = sf::View(sf::FloatRect(pos.x, pos.y, size.x * scale.x, size.y * scale.y));
	renderWindow->setView(view);
}

void Camera::Update(float deltaTime)
{
	Move(deltaTime);
	Scale(deltaTime);
	Rotate();
	renderWindow->setView(view);
}

void Camera::Move(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		transform->Translate({ 0.0f,-moveSpeed * deltaTime });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		transform->Translate({ 0.0f,+moveSpeed * deltaTime });
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		transform->Translate({ +moveSpeed * deltaTime,0.0f });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		transform->Translate({ -moveSpeed * deltaTime,0.0f });
	}
	view.setCenter(transform->GetLocalPosition());
}

void Camera::Scale(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		transform->Scale({ 1.0f + deltaTime, 1.0f + deltaTime });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		transform->Scale({ 1.0f - deltaTime, 1.0f - deltaTime });
	}
	moveSpeed = transform->GetLocalScale().x * 1000.0f;
	view.setSize(renderWindow->getSize().x * transform->GetLocalScale().x, renderWindow->getSize().y * transform->GetLocalScale().x);
}

void Camera::Rotate()
{
	view.setRotation(transform->GetLocalRotation());
}
