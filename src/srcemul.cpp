#include <iostream>
#include "srcemul.h"

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
}

void Screenemulator::clear()
{
#if defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void Screenemulator::draw()
{
    clear();
    for (int i = 0; i < _vsize; ++i)
    {
        for (int j = 0; j < _hsize; ++j)
        {
            std::cout << "\x1b[44m" << screen[i][j];
        }
        std::cout << "\x1b[0m" << std::endl;
    }
}