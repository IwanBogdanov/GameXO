#include "logicxo.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

LogicXO::LogicXO() :
    pos(START),
    range(3),
    gameOver(false),
    x(2),
    y(2)

{

}
int LogicXO::kbhit()
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
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

    if(i == x && i == y)
        cout << ".";

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

void LogicXO::curcor()
{
    switch (kbhit()) {
    case 'w':
        pos = UP;
        break;
    case 's':
        pos = DOWN;
        break;
    case 'a':
        pos = LEFT;
        break;
    case 'd':
        pos = RIGHT;
        break;
    }
}

bool LogicXO::getGameOver() const
{
    return gameOver;
}


