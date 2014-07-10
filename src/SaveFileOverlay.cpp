#include "SaveFileOverlay.hpp"

SaveFileOverlay::SaveFileOverlay()
    : TIME_VISIBLE(sf::milliseconds(200))
    , m_IsVisible(false)
{
    m_Texture.loadFromFile("res/saveOverlay.png");
    m_Texture.setSmooth(true);
}

void SaveFileOverlay::create(int width, int height)
{
    m_Width = width;
    m_Height = height;

    createShape();
}

void SaveFileOverlay::show()
{
    m_SaveTime = m_Clock.getElapsedTime();
    m_IsVisible = true;
}

void SaveFileOverlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    update();

    if (m_IsVisible)
        target.draw(m_Shape, states);
}

void SaveFileOverlay::update() const
{
    if (m_IsVisible)
    {
        if (m_Clock.getElapsedTime() - m_SaveTime >= TIME_VISIBLE)
            m_IsVisible = false;
    }
}

void SaveFileOverlay::createShape()
{
    m_Shape.setSize(sf::Vector2f(m_Width, m_Height));
    m_Shape.setFillColor(sf::Color::White);
    m_Shape.setTexture(&m_Texture);
}
