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
        void generate(Cell& currentCell);
        sf::Vector2i getRandomCell() const;
        bool allCellsVisited() const;
        std::vector<sf::Vector2i> getNeighbors(const Cell& cell) const;
        bool hasUnvisitedNeighbors(Cell& cell) const;

        void createCells();
        
    private:
        int m_Width;
        int m_Height;
        int m_NumCells;
        int m_CellWidth;
        int m_CellHeight;

        std::vector<std::vector<Cell>> m_Cells;
};

#endif

