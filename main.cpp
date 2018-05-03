#include <iostream>
#include "logicxo.h"

using namespace std;

int main()
{
    LogicXO game;
    while(!game.getGameOver())
    {
        game.draw();
    }
}
