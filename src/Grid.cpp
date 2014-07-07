#include "Grid.hpp"

void Grid::create()
{
    m_CellWidth = m_Width / m_NumCells;
    m_CellHeight = m_Height / m_NumCells;

    createLines();    
}

void Grid::setWidth(int width)
{
    m_Width = width; 
}

void Grid::setHeight(int height)
{
    m_Height = height; 
}

void Grid::setNumCells(int numCells)
{
    m_NumCells = numCells; 
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& line : m_Lines)
    {
        target.draw(line);
    }
}

void Grid::createLines()
{
    auto genRandColor = []()
    {
        auto red = rand() % 255;
        auto green = rand() % 255;
        auto blue = rand() % 255;

        return sf::Color(red, green, blue);
    };

    sf::RectangleShape line;
    for (int x = 0; x < m_NumCells; ++x)
    {
        for (int y = 0; y < m_NumCells; ++y)
        {
            // Horizontal line
            line.setFillColor(genRandColor());
            line.setSize(sf::Vector2f(m_CellWidth, 3.f));
            line.setPosition(x * m_CellWidth, y * m_CellHeight);
            m_Lines.push_back(line);

            // Vertical line
            line.setFillColor(genRandColor());
            line.setSize(sf::Vector2f(3.f, m_CellHeight));
            line.setPosition(x * m_CellWidth, y * m_CellHeight);
            m_Lines.push_back(line);

            // If needed, draw extra lines to "close" the cells
            // i.e. when x == m_NumCells - 1 or y == m_NumCells - 1
            if (x == m_NumCells - 1)
            {
                line.setFillColor(genRandColor());
                line.setSize(sf::Vector2f(3.f, m_CellHeight));
                line.setPosition((x + 1) * m_CellWidth, y * m_CellHeight);
                m_Lines.push_back(line);
            }

            if (y == m_NumCells - 1)
            {
                line.setFillColor(genRandColor());
                line.setSize(sf::Vector2f(m_CellWidth, 3.f));
                line.setPosition(x * m_CellWidth, (y + 1) * m_CellHeight);
                m_Lines.push_back(line);
            }
        }
    }
}
