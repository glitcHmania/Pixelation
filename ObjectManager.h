#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "UID.h"

class ObjectManager
{
public:
	ObjectManager() = default;
	std::shared_ptr<GameObject> Instantiate();
	void Destroy(std::shared_ptr<GameObject> object);

private:
	std::vector<std::shared_ptr<GameObject>> objects;
};
