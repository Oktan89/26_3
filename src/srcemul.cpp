#include <iostream>
#include "srcemul.h"
#include "wincl.h"

std::size_t Screenemulator::HWIdP = 0;

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
    for (auto &win : windows)
        delete win;
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

void Screenemulator::draw(Wincl &wincl)
{
    clear();
    for (int i = 0; i < _vsize; ++i)
    {
        for (int j = 0; j < _hsize; ++j)
        {
            if (screen[i][j] == wincl.fill)
            {
                std::cout << wincl.color << screen[i][j];
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

    for (int i = wincl._x; i < wincl._vsize + wincl._x; ++i)
    {
        for (int j = wincl._y; j < wincl._hsize + wincl._y; ++j)
        {
            if (!(i >= this->_vsize || j >= this->_hsize))
                screen[i][j] = wincl.fill;
        }
    }
    draw(wincl);
}

void Screenemulator::createWindow()
{
    if(HWIdP == 10)
    {
        std::cout<<"I'm sorry but you can't create more than 9 windows"<<std::endl;
        return;
    }
    Wincl *wincl;
    if (windows.size() != 0)
    {
        for (auto w : windows)
        {
            if (w->getPriority() == 0)
            {
                auto res = w->getDot();
                if(res.first + 1 >= _vsize)
                {
                    res.first = 0;
                    res.second = 0;
                }
                wincl = new Wincl(res.first + 1, res.second + 1, 6, 25);
                break;
            }
        }
    }
    else
    {
        wincl = new Wincl(_vsize / 2, _hsize / 2, 6, 25);
    }


    std::size_t np = HWIdP++;
    wincl->setHwidp(np);
    wincl->setPriority(allocation_of_priorities());
    wincl->setFill(std::to_string(np)[0]);
    windows.push_back(wincl);
    redraw(*wincl);
}

std::size_t Screenemulator::allocation_of_priorities()
{
    if(windows.size() == 0)
    {
        return 0;
    }
    else
    {
        
        for(auto winp : windows)
        {
            std::size_t i = winp->getPriority();
            winp->setPriority(++i);
        }
        return 0;
    }
}