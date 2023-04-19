#include <iostream>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Food.h"

Snake snake({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
Food food;

int score;

SoundPlayer sfxCollect = SoundPlayer{"EatApple.wav"};
SoundPlayer sfxLose = SoundPlayer{ "HitSomething.wav" };


void start_game()
{
    snake.Reset();
    system("cls");
    score = 0;
    srand(time(NULL));
    food.GenerateFood();
}

void update(Snake& snake, Food& food, bool& gameOver, int& score)
{
    // Handle user input
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'w': snake.ChangeDirection(UP   ); break;
            case 'a': snake.ChangeDirection(LEFT ); break;
            case 's': snake.ChangeDirection(DOWN ); break;
            case 'd': snake.ChangeDirection(RIGHT); break;
        }
    }

    // Update the game state
    if (snake.Collided())
    {
        gameOver = true;
        sfxLose.Play();
        return;
    }

    if (snake.FoodEaten(*food.GetPosition()))
    {
        food.GenerateFood();
        snake.Grow();
        sfxCollect.Play();
        score += 10;
    }

    snake.MoveSnake();

    // Render the game
    Renderer::Render(snake, food, score);
}

int main()
{
    while (true)
    {
        start_game();
        bool gameOver = false;
        // Initialise stuff and set values to 0

        while (!gameOver)
        {
            // Call the update function to update the game state and render the game
            update(snake, food, gameOver, score);

            // Sleep for a short period to control the game speed
            this_thread::sleep_for(chrono::milliseconds(75));

            // Clear the console before the next frame is rendered
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        }
    }
}