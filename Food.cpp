#include "Food.h"

void Food::GenerateFood()
{
    foodPosition.X = (rand() % (SCREEN_WIDTH - 2)) + 1;
    foodPosition.Y = (rand() % (SCREEN_HEIGHT - 2)) + 1;
}

const COORD* Food::GetPosition() const
{
    return &foodPosition;
}