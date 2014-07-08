#include "Grid.hpp"

void Grid::create()
{
    m_CellWidth = m_Width / m_NumCells;
    m_CellHeight = m_Height / m_NumCells;

    createCells();
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
    for (int x = 0; x < m_NumCells; ++x)
    {
        for (int y = 0; y < m_NumCells; ++y)
        {
            target.draw(m_Cells[x][y]);
        }
    }
}

void Grid::createCells()
{
    for (int x = 0; x < m_NumCells; ++x)
    {
        m_Cells.push_back(std::vector<Cell>());
        for (int y = 0; y < m_NumCells; ++y)
        {
            Cell cell(x, y, m_CellWidth, m_CellHeight);
            m_Cells[x].push_back(cell);
        }
    }
}
