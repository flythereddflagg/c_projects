#include "raylib.h"
#include "dbg.h"


int main(void)
{
    InitWindow(640, 360, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 100, 100, 20, LIGHTGRAY);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
