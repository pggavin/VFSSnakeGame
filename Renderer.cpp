#include <array>
#include "Renderer.h"
#include "GameData.h"

#include <iostream>
#include <string>

void Renderer::Render(const Snake& snake, const Food& food, int score)
{
    // gets the snakes position
    const COORD* snakePosition = snake.GetSnakePosition();
    const COORD* foodPosition = food.GetPosition();
    const vector<COORD>* snakeBody = snake.GetSnakeBody();

    array<array<string, SCREEN_WIDTH>, SCREEN_HEIGHT> board;

    // Initialize the game board with empty spaces and walls
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            if (j == 0 || j == SCREEN_WIDTH - 1)
            {
                board[i][j] = WALL;
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
    // creating the width boundary

    // Place snake body
    for (const auto& bodyPart : *snakeBody)
    {
        board[bodyPart.Y][bodyPart.X] = SNAKE_BODY;
    }

    // Place snake head
    board[snakePosition->Y][snakePosition->X] = SNAKE_HEAD;

    // Place food
    board[foodPosition->Y][foodPosition->X] = FRUIT;

    // Render the game board
    string buffer;
    buffer.reserve((SCREEN_WIDTH + 1) * SCREEN_HEIGHT);
    buffer += "SCORE : " + to_string(score) + "\n\n";

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        if (i != 0)
        {
            buffer += "\n";
        }

        if (i == 0 || i == SCREEN_HEIGHT - 1)
        {
            buffer += string(SCREEN_WIDTH * 2, '#');                                          
            // creating the height boundary 
        }

        else
        {
            for (int j = 0; j < SCREEN_WIDTH; j++)
            {
                buffer += board[i][j];
            }
        }
    }

    DRAW(buffer);
}