#include "Utils.h"
#include "Snake.h"
#include "Food.h"


Snake snake({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, 1);
Food food;

int score;

void board()
{
    // gets the snakes position
    COORD snakePosition = snake.GetSnakePosition();
    COORD foodPosition = food.GetPosition();

    vector<COORD> snakeBody = snake.GetSnakeBody();

    PRINT("SCORE : ", score);

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        DRAW("\t\t|");    
        for (int j = 0; j < SCREEN_WIDTH - 2; j++)                                          // creating the height boundary    
        {   
            if (i == 0 || i == SCREEN_HEIGHT - 1)                                       // creating the width boundary
            {
                DRAW('-');
            }

            else if (i == snakePosition.Y && j + 1 == snakePosition.X)                      // generate the snake body
            {
                DRAW('0');
            }
            else if (i == foodPosition.Y && j + 1 == foodPosition.X)                        // generate the food in level
            {
                DRAW('@');
            }
            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < snakeBody.size() - 1; k++)                          // increasing the size of snake 
                {
                    if (i == snakeBody[k].Y && j + 1 == snakeBody[k].X)                 // making the rest of the body if the snake consumes food
                    {
                        DRAW('o');
                        isBodyPart = true;
                        break;
                    }
                }

                if (!isBodyPart) DRAW(' ');
            }
        }
        DRAW("|\n");
    }
}

int main()
{
    score = 0;
    srand(time(NULL));

    food.GenerateFood();                                // calling the generate food in the main function to get the first element also as random

    char game_over = false;                             // game over loop

    while (!game_over)
    {
        board();                                        // creating the board

        if (_kbhit())                                   // checks the console for key strokes
        {
            switch (_getch())                           // gets the key stroke for keyboard strokes
            {
            case 'w': 
                snake.Direction('1'); 
                break;          
            case 'a': 
                snake.Direction('3'); 
                break;
            case 's': 
                snake.Direction('2'); 
                break;
            case 'd': 
                snake.Direction('4'); 
                break;
            }
        }

        if (snake.WallCollision())                      // if the snake collides with the wall then game over
        {
            game_over = true;
        }

        if (snake.FoodEaten(food.GetPosition()))                    // if the snake has eaten the food
        {
            food.GenerateFood();                                    // generate new food item
            snake.Grow();                                           // increase the snake length
            score = score + 10;                                     // increase the score
        }

        snake.MoveSnake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });         // removes the flickering screen
    }
}