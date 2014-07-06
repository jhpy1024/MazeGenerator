#include "Application.hpp"

Application::Application()
{
}

void Application::setWidth(int width)
{
    m_Width = width;
}

void Application::setHeight(int height)
{
    m_Height = height;
}

void Application::setNumCells(int numCells)
{
    m_NumCells = numCells;
}

void Application::run()
{
    createWindow();

    while (m_Window.isOpen())
    {
        handleInput();
        update();
        draw();
    }
}

void Application::handleInput()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_Window.close();
    }
}

void Application::update()
{

}

void Application::draw()
{
    m_Window.clear();

    m_Window.display();
}

void Application::createWindow()
{
    m_Window.create(sf::VideoMode(m_Width, m_Height), "Maze Generator!", sf::Style::Close);
}
