#include <ncurses.h>
#include <iostream>
#include <vector>

#include "Engine.h"

int main()
{
    Engine e;
    std::cout << std::endl << e.step() << std::endl;


    return 1;
}

