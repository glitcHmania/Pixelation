#pragma once
#include "GameObject.h"
#include "Geometry.h"
#include "Time.h"

class Player : public GameObject
{
public:
	Player(std::string UID);
	void Start() override;
	void Update() override;
	void SetSide(int i);

	void CheckCollision(const CollisionEvent& tesetevent);
public:
	Geometry::DynamicRect collider;
private:
	int side = 0;
	bool isColliding = false;
};