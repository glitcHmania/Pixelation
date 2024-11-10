#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include "UID.h"

namespace ObjectManager
{
	std::shared_ptr<GameObject> Instantiate();
	void Destroy(std::shared_ptr<GameObject> object);
};
