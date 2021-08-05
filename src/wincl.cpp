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