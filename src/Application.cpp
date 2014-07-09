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

void Application::setOutputPrefix(const std::string& prefix)
{
    m_OutputPrefix = prefix;
}

void Application::run()
{
    createWindow();
    createGrid();

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
        else if (event.type == sf::Event::KeyPressed)
            handleKeyPress(event);
    }
}

void Application::update()
{

}

void Application::draw()
{
    m_Window.clear(sf::Color(32, 32, 32));

    m_Window.setView(m_View);
    m_Window.draw(m_Grid);

    m_Window.display();
}

void Application::createWindow()
{
    m_Window.create(sf::VideoMode(m_Width, m_Height), "Maze Generator!", sf::Style::Close);

    m_View.setCenter(m_Width / 2.f, m_Height / 2.f);
    m_View.setSize(m_Width, m_Height);
    m_View.zoom(1.08f);
}

void Application::createGrid()
{
    m_Grid.setWidth(m_Width);
    m_Grid.setHeight(m_Height);
    m_Grid.setNumCells(m_NumCells);
    m_Grid.create();
}

void Application::handleKeyPress(const sf::Event& event)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Space:
            m_Grid.generateMaze();
            break;
        case sf::Keyboard::S:
            m_Grid.saveToFile(m_OutputPrefix);
            break;
        default:
            break;
    }
}
