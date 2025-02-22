#include <iostream>
#include <raylib.h>

#include "psycho.h"

using namespace std;

const int ScreenWidth = 800;
const int ScreenHeight = 600;

int main()
{
	InitWindow(ScreenWidth, ScreenHeight, "psycho2D");

    psycho2D::circle c1{ psycho2D::vec2(0.0f), 50.0f };
    psycho2D::circle c2{ psycho2D::vec2(ScreenWidth * 0.5f, ScreenHeight * 0.5f), 50.0f };


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({ 0, 0, 0, 255 });

        c1.c = psycho2D::vec2(GetMousePosition().x, GetMousePosition().y);

        psycho2D::collsion_manifold collision_data = psycho2D::circle_vs_circle(c1, c2);

        if (collision_data.collided)
        {
            c2.c.add(collision_data.normal);
        }

        DrawCircleLines(c1.c.x, c1.c.y, c1.r, GREEN);
        DrawCircleLines(c2.c.x, c2.c.y, c2.r, BLUE);

        EndDrawing();
    }

    CloseWindow();

	return 0;
}
