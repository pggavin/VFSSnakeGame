#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <Windows.h>

using namespace std;

class Snake
{
public:
    Snake(COORD pos, int vel);

    void grow();
    void move_snake();

    void change_direction(COORD newDirection);


    bool collided();
    bool eaten(COORD food);

    const vector<COORD>* get_body() const;
    const COORD* get_pos() const;

    void reset();

private:
    COORD pos;
    int vel;
    COORD m_direction;

    int len;
    vector<COORD> body;
};

#endif // SNAKE_H