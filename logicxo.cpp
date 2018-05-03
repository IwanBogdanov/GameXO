#include <iostream>
#include "logicxo.h"

using namespace std;

LogicXO::LogicXO() :
    range(3),
    gameOver(false)
{

}

void LogicXO::draw()
{
    system("clear");
    int k = 0;
    for(int l = 0; l < range; l++)
    {
    for(int i = 0; i < range; i++)
    {
    cout << " ";
    if(i == range/3 || i == (range/3)*2)
    {
    cout << "#";
    }
    }
    k++;

    if(k == range/3 || k == (range/3)*2)
    {
        cout << endl;
    for(int i = 0; i < (range*2)+1; i++)
    cout << "#";
    }
    cout<< endl;
    }
}

bool LogicXO::getGameOver() const
{
    return gameOver;
}


