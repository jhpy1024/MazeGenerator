#include "Cell.hpp"

Cell::Cell(int x, int y, int width, int height)
    : m_X(x)
    , m_Y(y)
    , m_Width(width)
    , m_Height(height)
    , m_Visited(false)
    , m_IsWalkable(false)
    , WALKABLE_COLOR(sf::Color::White)
    , NOT_WALKABLE_COLOR(sf::Color(128, 128, 128))
{
    setPosition(m_X * m_Width, m_Y * m_Height);
    createShape();
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_Shape);
}

void Cell::setVisited()
{
    m_Visited = true;
}

bool Cell::getIsVisited() const
{
    return m_Visited;
}

void Cell::setWalkable()
{
    m_IsWalkable = true;
    m_Shape.setFillColor(WALKABLE_COLOR);
}

bool Cell::getIsWalkable() const
{
    return m_IsWalkable;
}

void Cell::createShape()
{
    m_Shape.setSize(sf::Vector2f(m_Width, m_Height));
    m_Shape.setFillColor(NOT_WALKABLE_COLOR);
    m_Shape.setPosition(getPosition());
}
