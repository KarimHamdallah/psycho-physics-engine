#include <iostream>
#include <raylib.h>

#include "psycho.h"

using namespace std;

const int ScreenWidth = 800;
const int ScreenHeight = 600;

int main()
{
	InitWindow(ScreenWidth, ScreenHeight, "psycho2D");

    psycho2D::circle top_left{ psycho2D::vec2(-50.0f, -50.0f), 10.0f };
    psycho2D::circle bottom_left{ psycho2D::vec2(-50.0f, 50.0f), 10.0f };
    psycho2D::circle top_right{ psycho2D::vec2(50.0f, -50.0f), 10.0f };
    psycho2D::circle bottom_right{ psycho2D::vec2(50.0f, 50.0f), 10.0f };

    psycho2D::vec2 window_center(ScreenWidth * 0.5f, ScreenHeight * 0.5f);

    float angle = 0.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground({ 0, 0, 0, 255 });

        angle += 45 * GetFrameTime();

        psycho2D::vec2 top_left_rotated = psycho2D::rotate(top_left.c, angle);
        psycho2D::vec2 bottom_left_rotated = psycho2D::rotate(bottom_left.c, angle);
        psycho2D::vec2 top_right_rotated = psycho2D::rotate(top_right.c, angle);
        psycho2D::vec2 bottom_right_rotated = psycho2D::rotate(bottom_right.c, angle);

        psycho2D::vec2 top_left_translated = psycho2D::add(top_left_rotated, window_center);
        psycho2D::vec2 bottom_left_translated = psycho2D::add(bottom_left_rotated, window_center);
        psycho2D::vec2 top_right_translated = psycho2D::add(top_right_rotated, window_center);
        psycho2D::vec2 bottom_right_translated = psycho2D::add(bottom_right_rotated, window_center);

        DrawLine(top_left_translated.x, top_left_translated.y, top_right_translated.x, top_right_translated.y, GREEN);
        DrawLine(bottom_left_translated.x, bottom_left_translated.y, bottom_right_translated.x, bottom_right_translated.y, GREEN);
        DrawLine(top_left_translated.x, top_left_translated.y, bottom_left_translated.x, bottom_left_translated.y, GREEN);
        DrawLine(top_right_translated.x, top_right_translated.y, bottom_right_translated.x, bottom_right_translated.y, GREEN);

        DrawCircle(top_left_translated.x, top_left_translated.y, top_left.r, GREEN);
        DrawCircle(bottom_left_translated.x, bottom_left_translated.y, bottom_left.r, GREEN);
        DrawCircle(top_right_translated.x, top_right_translated.y, top_right.r, GREEN);
        DrawCircle(bottom_right_translated.x, bottom_right_translated.y, bottom_right.r, GREEN);

        EndDrawing();
    }

    CloseWindow();

	return 0;
}
