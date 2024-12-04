#include "Object.h"

std::type_index Object::GetType() const
{
    return typeid(*this);
}

bool Object::Equals(const Object& other) const
{
    return this == &other;
}

std::string Object::ToString() const
{
    return GetType().name();
}
