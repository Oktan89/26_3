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
    char fill;
    std::string color = "\x1b[40m";

   
    friend void Screenemulator::redraw(Wincl &wincl);
    friend void Screenemulator::draw(Wincl &wincl);

public:
    Wincl(std::size_t x = 10, std::size_t y = 10, std::size_t vsize = 6, std::size_t hsize = 25);
    void setHwidp(const std::size_t hwidp);
    void setPriority(const std::size_t priority);
    std::size_t getPriority();
    std::size_t getHWIdP();
    std::pair<std::size_t, std::size_t> getDot();
    void setFill(const char fill);
    void setDot(std::size_t x, std::size_t y);
    void setResolut(std::size_t vsize, std::size_t hsize);
};