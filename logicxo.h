#ifndef LOGICXO_H
#define LOGICXO_H


class LogicXO
{
public:
    enum moveCursor
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        START = 0
    };

    int kbhit(); //Anton version.

    LogicXO();
    void draw();
    void curcor();

    bool getGameOver() const;

private:
    moveCursor pos;
    int range;
    bool gameOver;
    int x, y;
};

#endif // LOGICXO_H
