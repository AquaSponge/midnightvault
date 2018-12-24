//engine.h
//#include "Engine.cpp"
#include <memory>
#include <vector>
#include "Character.h"

class Engine
{
public:

    std::vector<std::shared_ptr<Character>> characters;

    std::vector<int> testVec;

    int step();

    Engine();
};