#include <iostream>
#include "logicxo.h"

using namespace std;

LogicXO::LogicXO() :
    width(30),
    height(30)
{

}

void LogicXO::draw()
{
    for(int i = 0; i < width; i++)
    {
        if(i == 10 || i == 20)
            cout << "#";
        cout << " ";
        for(int j = 0; j < height; j++)
        {
            if(j == 10 || j == 20)
                cout << "#";
            cout << " ";
        }
    }
}
