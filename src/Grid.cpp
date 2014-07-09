#include "Grid.hpp"

#include <stack>

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
    drawCells(target, states);
    drawWalls(target, states);
}

void Grid::generateMaze()
{
    reset();

    auto totalCells = m_NumCells * m_NumCells;
    std::stack<sf::Vector2i> path;

    auto currentCell = getRandomCell();
    path.push(currentCell);
    auto numVisited = 1;

    while (numVisited < totalCells)
    {
        auto neighbors = getUnvisitedNeighbors(m_Cells[currentCell.x][currentCell.y]);
        if (!neighbors.empty())
        {
            auto randIndex = rand() % neighbors.size();
            auto randNeighbor = neighbors[randIndex];

            auto dx = randNeighbor.x - currentCell.x;
            auto dy = randNeighbor.y - currentCell.y;

            // If neighbor to right
            if (dx == 1)
            {
                m_Cells[currentCell.x][currentCell.y].openWall(Wall::East);
                m_Cells[randNeighbor.x][randNeighbor.y].openWall(Wall::West);
            }
            // If neighbor to left
            else if (dx == -1)
            {
                m_Cells[currentCell.x][currentCell.y].openWall(Wall::West);
                m_Cells[randNeighbor.x][randNeighbor.y].openWall(Wall::East);
            }
            // If neighbor above
            else if (dy == -1)
            {
                m_Cells[currentCell.x][currentCell.y].openWall(Wall::North);
                m_Cells[randNeighbor.x][randNeighbor.y].openWall(Wall::South);
            }
            // If neighbor below
            else if (dy == 1)
            {
                m_Cells[currentCell.x][currentCell.y].openWall(Wall::South);
                m_Cells[randNeighbor.x][randNeighbor.y].openWall(Wall::North);
            }

            m_Cells[randNeighbor.x][randNeighbor.y].setVisited();
            ++numVisited;
            currentCell = randNeighbor;
            path.push(currentCell);
        }
        else
        {
            currentCell = path.top();
            path.pop();
        }
    }
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

std::vector<sf::Vector2i> Grid::getNeighbors(const Cell& cell) const
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

std::vector<sf::Vector2i> Grid::getUnvisitedNeighbors(const Cell& cell) const
{
    std::vector<sf::Vector2i> neighbors;

    for (auto& neighbor : getNeighbors(cell))
    {
        if (!m_Cells[neighbor.x][neighbor.y].getIsVisited())
            neighbors.push_back(neighbor);
    }
    
    return neighbors;
}

sf::Vector2i Grid::getRandomNeighbor(const std::vector<sf::Vector2i>& neighbors) const
{
    auto randIndex = rand() % neighbors.size();
    return neighbors[randIndex];
}

bool Grid::hasUnvisitedNeighbors(Cell& cell) const
{
    return false;
}

void Grid::createCells()
{
    m_Cells.clear();
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

void Grid::drawCells(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int x = 0; x < m_NumCells; ++x)
    {
        for (int y = 0; y < m_NumCells; ++y)
        {
            target.draw(m_Cells[x][y]);
        }
    }

}

void Grid::drawWalls(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape wall;
    wall.setFillColor(sf::Color::White);
    wall.setOutlineThickness(1.f);
    wall.setOutlineColor(sf::Color::White);

    for (int x = 0; x < m_NumCells; ++x)
    {
        for (int y = 0; y < m_NumCells; ++y)
        {
            auto& cell = m_Cells[x][y];

            if (!cell.isWallOpen(Wall::North))
            {
                wall.setPosition(x * m_CellWidth, y * m_CellHeight);
                wall.setSize(sf::Vector2f(m_CellWidth, 1.f));
                target.draw(wall, states);
            }

            if (!cell.isWallOpen(Wall::East))
            {
                wall.setPosition((x + 1) * m_CellWidth, y * m_CellHeight);
                wall.setSize(sf::Vector2f(1.f, m_CellHeight));
                target.draw(wall, states);
            }

            if (!cell.isWallOpen(Wall::South))
            {
                wall.setPosition(x * m_CellWidth, (y + 1) * m_CellHeight);
                wall.setSize(sf::Vector2f(m_CellWidth, 1.f));
                target.draw(wall, states);
            }

            if (!cell.isWallOpen(Wall::West))
            {
                wall.setPosition(x * m_CellWidth, y * m_CellHeight);
                wall.setSize(sf::Vector2f(1.f, m_CellHeight));
                target.draw(wall, states);
            }
        }
    }
}

void Grid::reset()
{
    createCells();
}
