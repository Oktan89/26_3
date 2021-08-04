#pragma once
#include <vector>

class Screenemulator
{
    std::size_t _vsize;
    std::size_t _hsize;
    std::vector<std::vector<char>> screen;
    std::vector<std::vector<char>> buff;
    void clear();
    void draw();

public:
    Screenemulator(std::size_t vertical = 50, std::size_t horizontal = 80);
    ~Screenemulator();
};