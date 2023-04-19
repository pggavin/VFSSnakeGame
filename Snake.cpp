#include "Snake.h"
#include "GameData.h"
#include "CoordExtensions.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;

    len = 1;

    body.push_back(pos);

    m_direction = ZERO;
}

void Snake::change_direction(COORD newDirection)
{
    if (m_direction == (newDirection * INVERTED_COORD)) return;

    m_direction = newDirection;
}

void Snake::grow()
{
    len++;
}

COORD Snake::get_pos() const
{
    return pos;
}

vector<COORD> Snake::get_body() const
{
    return body;
}

void Snake::move_snake()
{
    pos += m_direction;

    body.push_back(pos);
    if (body.size() > len) body.erase(body.begin());
}

bool Snake::collided()
{
    if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2) return true;

    for (int i = 0; i < len - 1; i++)
    {
        if (pos.X == body[i].X && pos.Y == body[i].Y) return true;
    }
    return false;
}

bool Snake::eaten(COORD food)
{
    if (pos.X == food.X && pos.Y == food.Y) return true;
    return false;
}

void Snake::reset()
{
    // Generate a random position for the snake
    COORD new_pos = { rand() % WIDTH, rand() % HEIGHT };

    // Create a new Snake object with the random position and initial length of 1
    Snake new_snake(new_pos, 1);

    // Copy the new snake's state (position, direction, body) to this snake object
    pos = new_snake.pos;
    m_direction = ZERO;
    len = new_snake.len;
    body = new_snake.body;
}