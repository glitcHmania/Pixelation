#pragma once
#include <random>

namespace UID
{
	//UID is a string of 16 characters
	//A12dEf3ijkl5No9Q
	//Valid UID 
	std::string CreateUniqueID();
	std::string CreateLongUniqueID();
	std::string CreateCustomUniqueID(int length);
}

