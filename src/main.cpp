#include "Application.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    Application application;

    // Command line arguments format:
    //  <execute command> <width> <height> <num cells>
    if (argc != 4)
    {
        std::cout << "No arguments specified - Using defaults" << std::endl;

        application.setWidth(500);
        application.setHeight(500);
        application.setNumCells(10);
    }
    else
    {
        auto width = std::atoi(argv[1]);
        auto height = std::atoi(argv[2]);
        auto numCells = std::atoi(argv[3]);

        application.setWidth(width);
        application.setHeight(height);
        application.setNumCells(numCells);
    }

    application.run();

    return 0;
}

