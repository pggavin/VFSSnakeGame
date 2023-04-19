#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <Windows.h>

using namespace std;

class Snake
{
private:
    COORD pos;
    int vel;
    COORD m_direction;

    int len;
    vector<COORD> body;

public:
    Snake(COORD pos, int vel);

    void grow();
    void move_snake();

    void change_direction(COORD newDirection);

    vector<COORD> get_body() const;

    bool collided();
    bool eaten(COORD food);

    COORD get_pos() const;

    void reset();
};

#endif // SNAKE_H