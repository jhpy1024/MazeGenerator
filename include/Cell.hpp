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

        void setParent(Cell* parent);
        Cell* getParent() const;

        sf::Vector2i getPosition() const;
        
    private:
        void createShape();

    private:
        int m_X;
        int m_Y;
        int m_Width;
        int m_Height;

        bool m_Visited;

        sf::RectangleShape m_Shape;

        Cell* m_Parent;
};

#endif

