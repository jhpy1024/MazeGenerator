#ifndef GRID_HPP
#define GRID_HPP

class Grid
{
public:
   void create();

   void setWidth(int width);
   void setHeight(int height);
   void setNumCells(int numCells);
   
private:
    int m_Width;
    int m_Height;
    int m_NumCells;
};

#endif

