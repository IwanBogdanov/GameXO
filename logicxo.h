#ifndef LOGICXO_H
#define LOGICXO_H


class LogicXO
{
public:
    LogicXO();
    void draw();

    bool getGameOver() const;

private:
    int range;
    bool gameOver;
};

#endif // LOGICXO_H
