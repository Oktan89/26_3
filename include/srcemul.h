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
    void draw(const std::string &color = "\x1b[44m");
    //Wincl* wincl = nullptr;
    
public:
    Screenemulator(std::size_t vertical = 50, std::size_t horizontal = 80);
    ~Screenemulator();
    void redraw(Wincl &wincl);
    void createWindow();

};