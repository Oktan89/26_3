#pragma once
#include <iostream>
#include <string>
#include "srcemul.h"

class Wincl
{
    std::size_t _x{};
    std::size_t _y{};
    std::size_t _vsize{};
    std::size_t _hsize{};
    const char fill = '1';
    std::string color = "\x1b[40m";

    friend void Screenemulator::redraw(Wincl &wincl);
public:
    Wincl(std::size_t x = 10, std::size_t y = 10, std::size_t vsize = 5, std::size_t hsize = 10);
};