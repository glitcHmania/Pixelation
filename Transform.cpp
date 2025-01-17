#include "Transform.h"
#include <cmath>

#define DEG_TO_RAD (3.14159 / 180.0f) // Convert degrees to radians

void Transform::Scale(sf::Vector2f scaleFactor)
{
    scale.x *= scaleFactor.x;
    scale.y *= scaleFactor.y;
    matrixDirty = true;
}

void Transform::Rotate(float degrees)
{
    rotation += degrees;
    matrixDirty = true;
}

void Transform::Translate(sf::Vector2f delta)
{
    position += delta;
    matrixDirty = true;
}

void Transform::Translate(float x, float y)
{
    position += sf::Vector2f(x, y);
    matrixDirty = true;
}

void Transform::SetLocalPosition(sf::Vector2f pos)
{
    position = pos;
    matrixDirty = true;
}

void Transform::SetLocalPosition(float x, float y)
{
    position = sf::Vector2f(x, y);
    matrixDirty = true;
}

void Transform::SetLocalRotation(float rot)
{
    rotation = rot;
    matrixDirty = true;
}

void Transform::SetLocalScale(sf::Vector2f scl)
{
    scale = scl;
    matrixDirty = true;
}

sf::Vector2f Transform::GetLocalPosition() const
{
    return { position.x, position.y };
}

float Transform::GetLocalRotation() const
{
    return rotation;
}

sf::Vector2f Transform::GetLocalScale() const
{
    return { scale.x, scale.y };
}

sf::Vector2f Transform::GetRightVector() const
{
    float rad = rotation * DEG_TO_RAD;
    return sf::Vector2f(std::cos(rad), std::sin(rad));
}

sf::Vector2f Transform::GetUpVector() const
{
    float rad = rotation * DEG_TO_RAD;
    return sf::Vector2f(-std::sin(rad), std::cos(rad));
}

void Transform::Compose()
{
    float rad = rotation * DEG_TO_RAD;

    matrix[0] = std::cos(rad) * scale.x;
    matrix[1] = -std::sin(rad) * scale.y;
    matrix[2] = position.x;

    matrix[3] = std::sin(rad) * scale.x;
    matrix[4] = std::cos(rad) * scale.y;
    matrix[5] = position.y;

    matrix[6] = 0.0f;
    matrix[7] = 0.0f;
    matrix[8] = 1.0f;
}

float* Transform::GetMatrix()
{
    if (matrixDirty)
    {
        Compose();
        matrixDirty = false;
    }
    return matrix;
}

sf::Transform Transform::GetSF()
{
    if (matrixDirty)
    {
        Compose();
        matrixDirty = false;
    }

    return sf::Transform(matrix[0], matrix[1], matrix[2],
        matrix[3], matrix[4], matrix[5],
        matrix[6], matrix[7], matrix[8]);
}
