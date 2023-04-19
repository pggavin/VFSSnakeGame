#include "Food.h"

void Food::gen_food()
{
    pos.X = (rand() % (WIDTH - 2)) + 1;
    pos.Y = (rand() % (HEIGHT - 2)) + 1;
}

const COORD* Food::get_pos() const
{
    return &pos;
}