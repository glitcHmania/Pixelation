#pragma once
#include <string>
#include <typeinfo>
#include <typeindex>

class Object
{
public:
	std::type_index GetType() const;
	virtual bool Equals(const Object& other) const;
	virtual std::string ToString() const;

	template<typename T>
	bool IsOfType() const
	{
		return dynamic_cast<const T*>(this) != nullptr;
	}
protected:
	using UniqueID = std::string;
	UniqueID id = "";
};

