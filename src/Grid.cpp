#include "Grid.hpp"

void Grid::create()
{
    m_CellWidth = m_Width / m_NumCells;
    m_CellHeight = m_Height / m_NumCells;
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
}
