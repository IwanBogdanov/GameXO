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

void LogicXO::playersXO()
{
    do {
        cout << "Enter the name of the 1st player." << endl;
        gets(player1);
        cout << "Enter the name of the 2st player." << endl;
        gets(player2);
    }while(!strcmp(player1, player2));
}

void LogicXO::printXO()
{
    system("clear");
    cout << "Choose the number where you want to be like." << endl;
    cout << "-" << 1 << "-|-" << 2 << "-|-" << 3 << "-" << endl;
    cout << "-" << 4 << "-|-" << 5 << "-|-" << 6 << "-" << endl;
    cout << "-" << 7 << "-|-" << 8 << "-|-" << 9 << "-" << endl;
}
