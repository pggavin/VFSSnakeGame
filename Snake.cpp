#include "Snake.h"

Snake::Snake(COORD initialPosition)
{
    this->snakePosition = initialPosition;

    snakeLength = 1;
    // initial Snake Length
    body.push_back(initialPosition);
    // using a list to make the snake grow in size
    snakeDirection = ZERO;
}

// changes the snakes direction
void Snake::ChangeDirection(COORD newDirection)
{
    if (snakeDirection == (newDirection * INVERTED_COORD)) return;

    snakeDirection = newDirection;
}

// increases the snake length
void Snake::Grow()
{
    snakeLength++;
}

// returns the current position
const COORD* Snake::GetSnakePosition() const
{
    return &snakePosition;
}

// returns the current snake body
const vector<COORD>* Snake::GetSnakeBody() const
{
    return &body;
}

// move the snake in snakeDirection
void Snake::MoveSnake()
{
    snakePosition += snakeDirection;
    // add current direction to position
    body.push_back(snakePosition);
    if (body.size() > snakeLength) body.erase(body.begin()); // removes the first snake element from list
}

bool Snake::Collided()
{
    if (snakePosition.X < 1 || snakePosition.X > SCREEN_WIDTH - 2 || snakePosition.Y < 1 || snakePosition.Y > SCREEN_HEIGHT - 2)
    {
        return true;
    }
    // if the snake touches the bounds
    for (int i = snakeLength - 2; i > 0; --i)
    {
        if (snakePosition.X == body[i].X && snakePosition.Y == body[i].Y)
        {
            return true;
        }
        // if the snake collides with its own body part
    }
    return false;
}

bool Snake::FoodEaten(COORD food)
{
    return (snakePosition.X == food.X && snakePosition.Y == food.Y);
    // if the snake position is same as the food position
}

void Snake::Reset()
{
    // Generate a random position for the snake
    COORD new_pos = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT };

    // Create a new Snake object with the random position and initial length of 1
    Snake new_snake(new_pos);

    // Copy the new snake's state (position, directi, 1on, body) to this snake object
    snakePosition = new_snake.snakePosition;
    snakeDirection = ZERO;
    snakeLength = new_snake.snakeLength;
    body = new_snake.body;
}