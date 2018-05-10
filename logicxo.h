#ifndef LOGICXO_H
#define LOGICXO_H

class LogicXO
{
public:
    int kbhit(); //Anton version.
    void playersXO();
    void printXO();

private:
    char player1[100], player2[100];
    char arrXO[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
};

#endif // LOGICXO_H
