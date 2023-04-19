#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25

using namespace std;

class Snake
{
private:
    COORD snakePosition;                // position of snake in the level
    vector<COORD> body;

    int snakeVelocity;                  // snake velocity
    int snakeDirection;                // direction of the snake
    int snakeLength;                   // length of the snake

public:
    Snake(COORD initialPosition, int initialVelocity);

    void Grow();                                          // increase the snake length
    void MoveSnake();                                    // to move the snake
    void Direction(char changedDirection);               // changes the snakes direction

    vector<COORD> GetSnakeBody();                           // returns the new snake body

    bool WallCollision();                                    // checks collision with the walls
    bool FoodEaten(COORD food);

    COORD GetSnakePosition();                                    // returns the snake position
};

#endif // SNAKE_H