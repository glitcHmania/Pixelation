#include "UID.h"

namespace UID 
{
	namespace 
	{
		const int lowerLimit = 0x30;
		const int upperLimit = 0x7A;

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<> dist(lowerLimit, upperLimit);
	}

	std::string CreateUniqueID()
	{
		std::string unique_id;

		for (int i = 0; i < 16; i++)
		{
			unique_id.push_back(dist(mt));
		}

		return unique_id;
	}
	std::string CreateLongUniqueID()
	{
		std::string unique_id;

		for (int i = 0; i < 32; i++)
		{
			unique_id.push_back(dist(mt));
		}

		return unique_id;
	}
	std::string CreateCustomUniqueID(int length)
	{
		std::string unique_id;

		for (int i = 0; i < length; i++)
		{
			unique_id.push_back(dist(mt));
		}

		return unique_id;
	}
}