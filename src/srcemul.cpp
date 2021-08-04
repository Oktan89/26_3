#include <iostream>
#include "srcemul.h"
#include "wincl.h"

Screenemulator::Screenemulator(std::size_t vertical, std::size_t horizontal) : _vsize(vertical), _hsize(horizontal)
{
    screen.resize(_vsize);
    for (auto it = screen.begin(); it != screen.end(); ++it)
    {
        it->resize(_hsize);
    }

    for (int i = 0; i < _vsize; ++i)
    {
        for (int j = 0; j < _hsize; ++j)
        {
            screen[i][j] = ' ';
        }
    }
    buff = screen;
    draw();
}

Screenemulator::~Screenemulator()
{
    delete wincl;
}

void Screenemulator::clear()
{
#if defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void Screenemulator::draw(const std::string &color)
{
    clear();
    for (int i = 0; i < _vsize; ++i)
    {
        for (int j = 0; j < _hsize; ++j)
        {
            if(screen[i][j]=='-')
            {
                std::cout << color << screen[i][j];
            }
            else
            {
                std::cout << "\x1b[44m" << screen[i][j];
            }
            
        }
        std::cout << "\x1b[0m" << std::endl;
    }
}

void Screenemulator::redraw(Wincl &wincl)
{
    screen = buff;
    
    for (int i = wincl._x; i < wincl._vsize+wincl._x; ++i)
    {
        for (int j = wincl._y; j < wincl._hsize + wincl._y; ++j)
        {
            if(!(i >= this->_vsize || j >= this->_hsize))
                screen[i][j] = wincl.fill;
        }
    }
    draw(wincl.color);
}

void Screenemulator::createWindow()
{
    wincl = new Wincl(_vsize/2, _hsize/2, 6, 25);
    redraw(*wincl);
}