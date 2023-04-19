#include "Food.h"

void Food::GenerateFood()                                       // generates the food at a random location
{
    foodPosition.X = (rand() % SCREEN_WIDTH - 3) + 1;
    foodPosition.Y = (rand() % SCREEN_HEIGHT - 3) + 1;
}

COORD Food::GetPosition()               // returns the generated food location
{ 
    return foodPosition; 
}