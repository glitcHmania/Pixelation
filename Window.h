#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>


class Window
{
public:
	Window(sf::Vector2<unsigned int> resolution, std::string windowName);
	template<typename T>
	void Add(const T& drawable)
	{
		static_assert(std::is_base_of<sf::Drawable, T>::value, "Tried to push an undrawable object to the draw queue!");
		queue.push_back(std::make_unique<T>(drawable));
	}
	void Discard(int index);
	void Show();

private:
	std::vector<std::unique_ptr<sf::Drawable>> queue;
	std::unique_ptr<sf::RenderWindow> window;
	sf::Event eventHnd;
};
