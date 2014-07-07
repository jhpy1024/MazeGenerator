#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Grid.hpp"

#include <SFML/Graphics.hpp>

class Application
{
    public:
        Application();

        void setWidth(int width);
        void setHeight(int height);
        void setNumCells(int numCells);
        void setOutputFile(const std::string& fileName);

        void run();

        void handleInput();
        void update();
        void draw();

    private:
        void createWindow();
        void createGrid();

    private:
        int m_Width;
        int m_Height;
        int m_NumCells;
        std::string m_OutputFile;

        sf::RenderWindow m_Window;
        sf::View m_View;

        Grid m_Grid;
};

#endif
