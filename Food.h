#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdio>
#include "GameData.h"

class Food
{
public:
    void GenerateFood();
    const COORD* GetPosition() const;

private:
    COORD foodPosition;
};

#endif // FOOD_H