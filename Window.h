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
		queue.push_back(std::make_unique<T>(drawable));
	}

	template<typename T>
	void Discard(const T& drawable) 
	{
		for (int i = 0; i < queue.size(); i++)
			{
				if (&(*queue[i]) == &drawable)
				{
					queue.erase(queue.begin() + i, queue.begin() + i);
				}
			}
	}

	void Show();

private:
	std::vector<std::unique_ptr<sf::Drawable>> queue;
	std::unique_ptr<sf::RenderWindow> window;
	sf::Event eventHnd;
};
