#include <iostream>
#include "srcemul.h"

int main()
{
    Screenemulator test(20, 80);

    for(int i =0 ; i < 4; ++i)
    {
        test.createWindow();
    }
    int i, x ,y;
    while(true)
    {
        std::cin>>i;
        if(i == 10)
            return 0;

       // test.display(i);
        std::cout<<"Inpet x ,y:";
        std::cin>>x>>y;
        test.move(i, x, y);
        i = 5;

    }
     
    return 0; 
}