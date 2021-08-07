#pragma once
#include <vector>

class Wincl;

class Screenemulator
{
    std::size_t _vsize;
    std::size_t _hsize;
    static std::size_t HWIdP;
    std::vector<std::vector<char>> screen;
    std::vector<std::vector<char>> buff;
    std::vector<Wincl *> windows;
    
    void clear();
    
    std::size_t allocation_of_priorities();
    static bool winsort(Wincl* ws, Wincl* we);
public:
    Screenemulator(std::size_t vertical = 50, std::size_t horizontal = 80);
    ~Screenemulator();
    void redraw(Wincl &wincl);
    void draw();
    void draw(Wincl &wincl);
    void createWindow();
    void display(const std::size_t hwidp = 0);
    void move(const std::size_t hwidp, std::size_t x, std::size_t y);
    void resize(const std::size_t hwidp, std::size_t vsize, std::size_t hsize);
};