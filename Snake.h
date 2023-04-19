#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <Windows.h>

using namespace std;

class Snake
{
public:
    Snake(COORD initialPosition);

    void Grow();
    void MoveSnake();

    void ChangeDirection(COORD newDirection);

    bool Collided();
    bool FoodEaten(COORD food);

    const vector<COORD>* GetSnakeBody() const;
    const COORD* GetSnakePosition() const;

    void Reset();

private:
    COORD snakePosition;
    COORD snakeDirection;

    int snakeLength;
    vector<COORD> body;
};

#endif // SNAKE_H