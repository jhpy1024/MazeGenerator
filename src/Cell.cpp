#include "Cell.hpp"

Cell::Cell(int x, int y, int width, int height)
    : m_X(x)
    , m_Y(y)
    , m_Width(width)
    , m_Height(height)
    , m_Visited(false)
    , m_Parent(nullptr)
{
    setPosition(m_X * m_Width, m_Y * m_Height);
    createShape();
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_Shape, states);
}

void Cell::setVisited()
{
    m_Visited = true;
}

bool Cell::getIsVisited() const
{
    return m_Visited;
}

void Cell::setParent(Cell* parent)
{
    m_Parent = parent;
}

Cell* Cell::getParent() const
{
    return m_Parent;    
}

sf::Vector2i Cell::getPosition() const
{
    return { m_X, m_Y };
}

void Cell::createShape()
{
    m_Shape.setSize(sf::Vector2f(m_Width, m_Height));
    m_Shape.setFillColor(sf::Color::White);
}
