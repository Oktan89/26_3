#include <iostream>
#include <sstream>
#include "srcemul.h"

int main()
{
    Screenemulator win(20, 80);

    std::string answer;
    std::stringstream enter;

    while (true)
    {
        enter.str("");
        enter.clear();
        std::cout << "bash Windows ASCII : ";
        std::getline(std::cin, answer);
        enter << answer;
        if (enter.fail())
        {
            enter.str("");
            enter.clear();
            continue;
        }
        std::string text;
        enter >> text;
        if (text == "exit")
        {
            std::cout << "Exit" << std::endl;
            return 0;
        }
        else if (text == "create")
        {
            win.createWindow();
            continue;
        }
        else if (text == "display")
        {
            std::size_t hwindp;
            enter >> hwindp;
            if (enter.fail())
            {
                win.display();
            }
            else
            {
                win.display(hwindp);
            }
            continue;
        }
        else if (text == "move")
        {
            std::size_t hwindp, x, y;
            enter >> hwindp >> x >> y;
            if (enter.fail())
            {
                win.draw();
                std::cout << "Incorrect enter" << std::endl;
                ;
                continue;
            }
            else
            {
                win.move(hwindp, x, y);
            }
            continue;
        }
        else if (text == "resize")
        {
            std::size_t hwindp, vsize, hsize;
            enter >> hwindp >> vsize >> hsize;
            if (enter.fail())
            {
                win.draw();
                std::cout << "Incorrect enter" << std::endl;
                ;
                continue;
            }
            else
            {
                win.resize(hwindp, vsize, hsize);
            }
            continue;
        }
        win.draw();
        std::cout << "bash error: The command was not found" << std::endl;
    }

    return 0;
}