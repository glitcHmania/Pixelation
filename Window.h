#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window
{
public:
	Window(sf::Vector2<unsigned int> resolution, std::string windowName);
	template<typename T>
	void Add( const std::shared_ptr<T> drawable)
	{
		if (!(std::is_base_of<sf::Drawable, T>::value)) 
			throw("Tried to push an undrawable object to the draw queue!");
		queue.push_back(drawable);
	}
	void Discard(int index);
	void Show();

private:
	std::unique_ptr<sf::RenderWindow> window;
	std::vector<std::shared_ptr<sf::Drawable>> queue;
	sf::Event eventHnd;
};
