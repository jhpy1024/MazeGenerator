#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

class Application
{
    public:
        Application();

        void setWidth(int width);
        void setHeight(int height);
        void setNumCells(int numCells);

        void run();

        void handleInput();
        void update();
        void draw();

    private:
        void createWindow();

    private:
        int m_Width;
        int m_Height;
        int m_NumCells;

        sf::RenderWindow m_Window;
};

#endif
