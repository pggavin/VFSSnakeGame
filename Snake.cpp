#include "Snake.h"

Snake::Snake(COORD initialPosition, int initialVelocity)
{
    this->snakePosition = initialPosition;
    this->snakeVelocity = initialVelocity;

    snakeDirection = 'n';
    snakeLength = 1;                                            // initial Snake Length

    body.push_back(initialPosition);                            // using a list to make the snake grow in size
}

void Snake::Direction(char changedDirection)                // changes the snakes direction
{ 
    this->snakeDirection = changedDirection; 
}   
        
void Snake::Grow()                                          // increases the snake length
{ 
    snakeLength++; 
}

COORD Snake::GetSnakePosition()                                      // returns the updated position
{ 
    return snakePosition; 
}

vector<COORD> Snake::GetSnakeBody()                                 // returns the updated snake body
{ 
    return body; 
}        

void Snake::MoveSnake()                                // move the snake up and down
{
    switch (snakeDirection)
    {
    case '1': 
        snakePosition.Y -= snakeVelocity;            // decrease the snake's y co-ordinate to move up
        break;                                      
    case '2': 
        snakePosition.Y += snakeVelocity;           // increase the snake's y co-ordinate to move down
        break;                                      
    case '3': 
        snakePosition.X -= snakeVelocity;           // decrease the snake's x co-ordinate to move left
        break;                                      
    case '4': 
        snakePosition.X += snakeVelocity;           // increase the snake's x co-ordinate to move right
        break;                                      
    }

    if(snakePosition.X > SCREEN_WIDTH - 2)          // if the snake collides with the side walls then spawn from the opposite wall
    {
        snakePosition.X = 0;
    }

    if (snakePosition.X < 1)                            // if the snake collides with the side walls then spawn from the opposite wall
    {
        snakePosition.X = SCREEN_WIDTH - 2;
    }


    body.push_back(snakePosition);
    if (body.size() > snakeLength) body.erase(body.begin());            // removes the first snake element from list
}

bool Snake::WallCollision()
{
    if (snakePosition.X < 1 || snakePosition.X > SCREEN_WIDTH - 2 || snakePosition.Y < 1 || snakePosition.Y > SCREEN_HEIGHT - 2)        // if the snake touches the bounds
    {
        return true;
    }

    for (int i = 0; i < snakeLength - 1; i++)
    {
        if (snakePosition.X == body[i].X && snakePosition.Y == body[i].Y)                       // if the snake collides with its own body part
        {
            return true;
        }
    }
    return false;
}

bool Snake::FoodEaten(COORD food)
{
    if (snakePosition.X == food.X && snakePosition.Y == food.Y)             // if the snake position is same as the food position
    {
        return true;
    }
    return false;
}