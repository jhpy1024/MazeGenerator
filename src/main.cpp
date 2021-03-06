#include "Application.hpp"

#include <iostream>
#include <ctime>

// Command line arguments format:
//  ./MazeGenerator <width> <height> <num cells> <output file>
int main(int argc, char** argv)
{
    srand(time(NULL));

    Application application;

    int width = 500;
    int height = 500;
    int numCells = 10;
    std::string outputPrefix = "maze";

    if (argc != 1)
    {
        if (argc == 5)
        {
            width = std::atoi(argv[1]);
            height = std::atoi(argv[2]);
            numCells = std::atoi(argv[3]);
            outputPrefix = std::string(argv[4]);
        }
        else
        {
            std::printf("==\nIncorrect arguments. Using defaults\n");
            std::printf("Usage: ./MazeGenerator <width> <height> <num cells> <output prefix>\n==\n\n");
        }
    }


    std::printf("Width: %i\nHeight: %i\nNum Cells: %i\nOutput prefix: %s\n", width, height, numCells, outputPrefix.c_str());

    application.setWidth(width);
    application.setHeight(height);
    application.setNumCells(numCells);
    application.setOutputPrefix(outputPrefix);

    application.run();

    return 0;
}

