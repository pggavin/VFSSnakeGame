#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;

    dir = 'n';
    len = 1;

    body.push_back(pos);
}

void Snake::direction(char dir) { this->dir = dir; }
void Snake::grow() { len++; }
COORD Snake::get_pos() { return pos; }

vector<COORD> Snake::get_body() { return body; }

void Snake::move_snake()
{
    switch (dir)
    {
    case 'u': pos.Y -= vel; break;
    case 'd': pos.Y += vel; break;
    case 'l': pos.X -= vel; break;
    case 'r': pos.X += vel; break;
    }

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
    dir = new_snake.dir;
    len = new_snake.len;
    body = new_snake.body;
}