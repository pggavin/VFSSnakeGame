#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdio>
#include "GameData.h"

class Food
{
private:
    COORD pos;

public:
    void gen_food();

    COORD get_pos() const;
};

#endif // FOOD_H