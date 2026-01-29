#include "raylib.h"
#include "raymath.h"
#include "dbg.h"


int main(void)
{
    Vector2 pos = {100, 100}, newpos = {1, 1};
    int i = 1;
    InitWindow(640, 360, "Test Game");
    SetTargetFPS(15);

    while (!WindowShouldClose())
    {
        i += 1;
        newpos.x = cos(i/100.0);
        newpos.y = sin(i/100.0);
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            DrawTextEx(
                GetFontDefault(),
                "A",
                Vector2Add(Vector2Multiply(pos, newpos), pos),
                20,
                0, 
                BLACK
            );
            printf("%f, %f\n", Vector2Multiply(pos, newpos).x, Vector2Multiply(pos, newpos).y);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
