#ifndef GRID_HPP
#define GRID_HPP

#include "Cell.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

class Grid : public sf::Drawable
{
    public:
        void create();

        void setWidth(int width);
        void setHeight(int height);
        void setNumCells(int numCells);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void generateMaze();

    private:
        sf::Vector2i getRandomCell() const;
        bool allCellsVisited() const;
        std::vector<sf::Vector2i> getNeighbors(const Cell& cell) const;
        std::vector<sf::Vector2i> getUnvisitedNeighbors(const Cell& cell) const;
        sf::Vector2i getRandomNeighbor(const std::vector<sf::Vector2i>& neighbors) const;
        bool hasUnvisitedNeighbors(Cell& cell) const;

        void createCells();

        void drawCells(sf::RenderTarget& target, sf::RenderStates states) const;
        void drawWalls(sf::RenderTarget& target, sf::RenderStates states) const;

        void reset();
        
    private:
        int m_Width;
        int m_Height;
        int m_NumCells;
        int m_CellWidth;
        int m_CellHeight;

        std::vector<std::vector<Cell>> m_Cells;
};

#endif

