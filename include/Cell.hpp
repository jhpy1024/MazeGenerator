#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

class Cell : public sf::Drawable, public sf::Transformable
{
    public:
        Cell(int x, int y, int width, int height);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void setVisited();
        bool getIsVisited() const;

        void setWalkable();
        bool getIsWalkable() const;

    private:
        void createShape();

    private:
        int m_X;
        int m_Y;
        int m_Width;
        int m_Height;

        bool m_Visited;
        bool m_IsWalkable;

        sf::RectangleShape m_Shape;
        const sf::Color WALKABLE_COLOR;
        const sf::Color NOT_WALKABLE_COLOR;
};

#endif

