#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

#include <bitset>

enum class Wall
{
    North, East, South, West
};

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

        void openWall(Wall wall);
        bool isWallOpen(Wall wall) const;
        
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

        // m_Walls[0]: North
        // m_Walls[1]: East
        // m_Walls[2]: South
        // m_Walls[3]: West
        // m_Walls[i] is true if the wall is open
        std::bitset<4> m_Walls;
};

#endif

