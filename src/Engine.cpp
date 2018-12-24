#include "Engine.h"
#include <random>

Engine::Engine()
{
    //initialize a few Character objects
    for(int k = 0; k < 3; ++k)
    {
        characters.push_back(std::make_shared<Character>(k));
    }



}

int Engine::step() //blah
{
    return 1911;
}