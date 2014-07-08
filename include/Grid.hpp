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

    private:
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

