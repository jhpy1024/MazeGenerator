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

void Grid::generateMaze()
{
    auto randCellPos = getRandomCell();
    generate(m_Cells[randCellPos.x][randCellPos.y]);
}

void Grid::generate(Cell& currentCell)
{
    // If all the cells have been visited, the
    // algorithm is complete
    if (allCellsVisited())
        return;

    
}

sf::Vector2i Grid::getRandomCell() const
{
    int x = rand() % m_NumCells;
    int y = rand() % m_NumCells;

    return { x, y };
}

bool Grid::allCellsVisited() const
{
    bool allVisited = true;

    for (int x = 0; x < m_NumCells; ++x)
    {
        for (int y = 0; y < m_NumCells; ++y)
        {
            allVisited = m_Cells[x][y].getIsVisited();
        }
    }

    return allVisited;
}

std::vector<sf::Vector2i> Grid::getNeighbors(Cell& cell) const
{
    auto pos = cell.getPosition();
    std::vector<sf::Vector2i> neighbors;

    // Top left corner
    if (pos.x == 0 && pos.y == 0)
    {
        neighbors.push_back(sf::Vector2i(pos.x + 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y + 1));
    }
    // Top right corner
    else if (pos.x == m_NumCells - 1 && pos.y == 0)
    {
        neighbors.push_back(sf::Vector2i(pos.x - 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y + 1));
    }
    // Bottom right corner
    else if (pos.x == m_NumCells - 1 && pos.y == m_NumCells - 1)
    {
        neighbors.push_back(sf::Vector2i(pos.x - 1, pos.y));
        neighbors.push_back({ pos.x, pos.y - 1});
    }
    // Bottom left corner
    else if (pos.x == 0 && pos.y == m_NumCells - 1)
    {
        neighbors.push_back(sf::Vector2i(pos.x + 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y - 1));
    }
    // Left edge
    else if (pos.x == 0)
    {  
        neighbors.push_back(sf::Vector2i(pos.x, pos.y - 1));
        neighbors.push_back(sf::Vector2i(pos.x + 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y + 1));
    }
    // Right edge
    else if (pos.x == m_NumCells - 1)
    {
        neighbors.push_back(sf::Vector2i(pos.x, pos.y - 1));
        neighbors.push_back(sf::Vector2i(pos.x - 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y + 1));
    }
    // Top edge
    else if (pos.y == 0)
    {
        neighbors.push_back(sf::Vector2i(pos.x - 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y + 1));
        neighbors.push_back(sf::Vector2i(pos.x + 1, pos.y));
    }
    // Bottom edge
    else if (pos.y == m_NumCells - 1)
    {
        neighbors.push_back(sf::Vector2i(pos.x - 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y - 1));
        neighbors.push_back(sf::Vector2i(pos.x + 1, pos.y));
    }
    // Not on edge or in corner
    else
    {
        neighbors.push_back(sf::Vector2i(pos.x - 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x + 1, pos.y));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y - 1));
        neighbors.push_back(sf::Vector2i(pos.x, pos.y + 1));
    }

    return neighbors;
}

bool Grid::hasUnvisitedNeighbors(Cell& cell) const
{
    return false;
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
