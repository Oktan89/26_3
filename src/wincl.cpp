#include <utility>
#include "wincl.h"

Wincl::Wincl(std::size_t x, std::size_t y, std::size_t vsize, std::size_t hsize) :
    _x(x), _y(y), _vsize(vsize), _hsize(hsize)
{
    
}

void Wincl::setHwidp(const std::size_t hwidp)
{
    _hwidp = hwidp;
}

void Wincl::setPriority(const std::size_t priority)
{
    _window_priority = priority;
}

std::size_t Wincl::getPriority()
{
    return _window_priority;
}

std::pair<std::size_t, std::size_t> Wincl::getDot()
{
    return std::make_pair(_x, _y);
}

void Wincl::setFill(const char fill)
{
    this->fill = fill;
}

std::size_t Wincl::getHWIdP()
{
    return _hwidp;
}

void Wincl::setDot(std::size_t x, std::size_t y)
{
    _x = y;
    _y = x;
}