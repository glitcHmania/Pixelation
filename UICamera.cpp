#include "UICamera.h"

UICamera::UICamera()
	:
	renderWindow(nullptr)
{
}

UICamera::UICamera(sf::RenderWindow& _renderWindow)
	:
	renderWindow(&_renderWindow)
{
	sf::Vector2 size = renderWindow->getSize();
	view = sf::View(sf::FloatRect(0.0f,0.0f, (float)size.x, (float)size.y));
}

void UICamera::SetFocus()
{
	renderWindow->setView(view);
}

void UICamera::SetRenderWindow(sf::RenderWindow& renderWin)
{
	renderWindow = &renderWin;
	sf::Vector2 size = renderWindow->getSize();
	view = sf::View(sf::FloatRect(0.0f, 0.0f, (float)size.x, (float)size.y));
}

void UICamera::ResizeWindow()
{
	sf::Vector2 size = renderWindow->getSize();
	view = sf::View(sf::FloatRect(0.0f, 0.0f, (float)size.x, (float)size.y));
}
