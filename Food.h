#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdio>
#include "GameData.h"

class Food
{
public:
    void gen_food();
    const COORD* get_pos() const;

private:
    COORD pos;
};

#endif // FOOD_H