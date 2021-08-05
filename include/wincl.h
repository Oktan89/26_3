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
    std::size_t _hwidp{};
    std::size_t _window_priority{};
    const char fill = '-';
    std::string color = "\x1b[40m";


    friend void Screenemulator::redraw(Wincl &wincl);
public:
    Wincl(std::size_t x = 10, std::size_t y = 10, std::size_t vsize = 6, std::size_t hsize = 25);
    void setHwidp(const std::size_t hwidp);
    void setPriority(const std::size_t priority);
    std::size_t getPriority();
};