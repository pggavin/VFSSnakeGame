#pragma once

#define SCREEN_HEIGHT 20
#define SCREEN_WIDTH 20

#define UP    COORD {  0, -1 }
#define DOWN  COORD {  0,  1 }
#define LEFT  COORD { -1,  0 }
#define RIGHT COORD {  1,  0 }
#define ZERO  COORD {  0,  0 }

#define SNAKE_HEAD "()"
#define SNAKE_BODY "<>"
#define FRUIT "O-"

#define EMPTY "  "
#define WALL "##"

#define DRAW(X) std::cout << X 