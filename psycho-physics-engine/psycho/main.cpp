#include <iostream>
#include <raylib.h>

#include "psycho.h"

using namespace std;

const int ScreenWidth = 800;
const int ScreenHeight = 600;

int main()
{
	std::cout << "Hello!\n";

	InitWindow(ScreenWidth, ScreenHeight, "basic window");

    psycho::circle c1{ {400.0f, 300.0f}, 20.0f };
    psycho::circle c2{ {450.0f, 350.0f}, 20.0f };


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({ 0, 0, 0, 255 });

        c1.c.x = GetMousePosition().x;
        c1.c.y = GetMousePosition().y;

        psycho::collsion_manifold collision_data = psycho::circlevscircle(c1, c2);

        if (collision_data.collided)
        {
            c2.c.Add(collision_data.normal);
        }

        DrawCircleLines(c1.c.x, c1.c.y, c1.r, GREEN);
        DrawCircleLines(c2.c.x, c2.c.y, c2.r, BLUE);

        EndDrawing();
    }

    CloseWindow();

	return 0;
}
