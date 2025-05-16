#pragma once
#include <SFML/System/Vector2.hpp>

namespace Geometry
{
    class Shape 
    {
    public:
        Shape() = default;

        virtual void Place(sf::Vector2f position) = 0;
        virtual bool Contains(const sf::Vector2f point) const = 0;
    };
    class Rect : public Shape
    {
    public:
        Rect(sf::Vector2f position, sf::Vector2f size);
        void Place(sf::Vector2f position) override;

        // Check if this rectangle intersects with another
        bool Intersects(const Rect& other) const;

        //Check if a point is inside the rectangle
        bool Contains(const sf::Vector2f point) const override;

        sf::Vector2f topLeft, bottomRight;
    };

    class Sphere : public Shape 
    {
    public:
        Sphere(sf::Vector2f center, float radius);
        void Place(sf::Vector2f position) override;
        
        bool Intersects(const Sphere& other);
        
        virtual bool Contains(const sf::Vector2f point) const override;

        sf::Vector2f center; 
        float radius; 
    };

    class Capsule : public Shape
    {
    public:
        Capsule(sf::Vector2f start, sf::Vector2f end, float radius);
        void Place(sf::Vector2f position) override;
        
        bool Intersects(const Capsule& other);
        
        virtual bool Contains(const sf::Vector2f point) const override;

    private:
        float Clamp(float n, float min, float max);
        float ClosestPtSegmentSegment(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2,
            sf::Vector2f q2, sf::Vector2f& c1, sf::Vector2f& c2);
    public:
        sf::Vector2f start, end;
        float radius;
    };

};