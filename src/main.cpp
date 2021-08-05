#include <iostream>
#include "srcemul.h"

int main()
{
    Screenemulator test(20, 80);

    for(int i =0 ; i < 15; ++i)
    {
        test.createWindow();
    }
    
 
     
    return 0; 
}