#include "Renderer.h"
#include "GameData.h"
#include <array>
#include <iostream>
#include <string>

void Renderer::render(const Snake& snake, const Food& food, int score)
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    vector<COORD> snake_body = snake.get_body();

    string buffer;
    buffer.reserve((WIDTH + 1) * HEIGHT);

    buffer += "SCORE : " + to_string(score) + "\n\n";

    for (int i = 0; i < HEIGHT; i++)
    {
        buffer += LEFT_WALL;

        for (int j = 0; j < WIDTH - 2; j++)
        {
            string tile = EMPTY;

            if (i == 0 || i == HEIGHT - 1)
            {
                tile = WALL;
            }
            else if (i == snake_pos.Y && j + 1 == snake_pos.X)
            {
                tile = SNAKE_HEAD;
            }
            else if (i == food_pos.Y && j + 1 == food_pos.X)
            {
                tile = FRUIT;
            }
            else
            {
                for (int k = 0; k < snake_body.size() - 1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        tile = SNAKE_BODY;
                        break;
                    }
                }
            }

            buffer += tile;
        }

        buffer += RIGHT_WALL;
    }

    cout << buffer;
}
