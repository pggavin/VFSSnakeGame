#include <conio.h>
#include <chrono>
#include <thread>

#include "Renderer.h"
#include "SoundPlayer.h"

void update(Snake& snake, Food& food, bool& game_over, int& score);
void start_game();

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);
Food food;

int score;

SoundPlayer collect_sound = SoundPlayer{"EatApple.wav"};
SoundPlayer lose_sound = SoundPlayer{ "HitSomething.wav" };

int main()
{
    while (true)
    {
        start_game();
        bool game_over = false;
        // Initialise stuff and set values to 0

        while (!game_over)
        {
            // Call the update function to update the game state and render the game
            update(snake, food, game_over, score);

            // Sleep for a short period to control the game speed
            this_thread::sleep_for(chrono::milliseconds(75));

            // Clear the console before the next frame is rendered
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        }
    }
}

void update(Snake& snake, Food& food, bool& game_over, int& score)
{
    // Handle user input
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'w': snake.change_direction(UP   ); break;
            case 'a': snake.change_direction(LEFT ); break;
            case 's': snake.change_direction(DOWN ); break;
            case 'd': snake.change_direction(RIGHT); break;
        }
    }

    // Update the game state
    if (snake.collided())
    {
        game_over = true;
        lose_sound.Play();
        return;
    }

    if (snake.eaten(food.get_pos()))
    {
        food.gen_food();
        snake.grow();
        collect_sound.Play();
        score += 10;
    }

    snake.move_snake();

    // Render the game
    Renderer::render(snake, food, score);
}

void start_game()
{
    snake.reset();
    system("cls");
    score = 0;
    srand(time(NULL));
    food.gen_food();
}