//#include "Player.h"
//
//
//Player::Player(std::string UID)
//	: GameObject(UID)
//{
//}
//
//void Player::Start()
//{
//	float halfExt[2] = { transform->GetLocalScale().x /2.0f , transform->GetLocalScale().y/2.0f  };
//	sf::Vector2f axes[2] = {transform->GetLocalAxis(0), transform->GetLocalAxis(1)};
//	transform->SetLocalPosition(sf::Vector2f(10.0f, 0.0f));
//
//	collider.Update(halfExt,transform->GetLocalPosition(), axes);
//	EventDispatcher::GetInstance().RegisterToEvent<CollisionEvent>(this, &Player::CheckCollision);
//}
//
//void Player::Update()
//{
//	float speed = 100.0f;
//	if (side == 0)
//	{
//		sf::Keyboard::isKeyPressed(sf::Keyboard::D);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		{
//			transform->Translate(speed * Time::GetDeltatime(), 0.0f);
//		}
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		{
//			transform->Translate(-speed * Time::GetDeltatime(), 0.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//		{
//			transform->Translate(0.0f, speed * Time::GetDeltatime());
//		}
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//		{
//			transform->Translate(0.0f, -speed * Time::GetDeltatime());
//		}
//	}
//	else
//	{
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//		{
//			transform->Translate(speed * Time::GetDeltatime(), 0.0f);
//		}
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//		{
//			transform->Translate(-speed * Time::GetDeltatime(), 0.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//		{
//			transform->Translate(0.0f, speed * Time::GetDeltatime());
//		}
//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//		{
//			transform->Translate(0.0f, -speed * Time::GetDeltatime());
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
//		{
//			transform->Rotate(30.0f * Time::GetDeltatime());
//		}
//	}
//
//	if (isColliding)
//	{
//		std::cout << "COLLISION ALERT" << side << std::endl;
//	}
//
//	sf::Vector2f axes[2] = { transform->GetLocalAxis(0), transform->GetLocalAxis(1) };
//	collider.Update(collider.halfExt, transform->GetLocalPosition(), axes);
//	EventDispatcher::GetInstance().DispatchImmediate<CollisionEvent>(CollisionEvent{collider});
//}
//
//void Player::SetSide(int i)
//{
//	side = i;
//}
//
//void Player::CheckCollision(const CollisionEvent& tesetevent)
//{
//	if (collider.center != tesetevent.collider.center && tesetevent.collider.Intersects(collider))
//	{
//		isColliding = true;
//	}
//	else
//	{
//		isColliding = false;
//	}
//}
