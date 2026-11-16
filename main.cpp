#include "raylib.h"
#include "raymath.h"

int main()
{
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "GOD");
    SetTargetFPS(60);

    Vector2 player{screenWidth / 2.0f, screenHeight / 2.0f};
    constexpr float speed = 300.0f;
    constexpr float radius = 24.0f;

    while (!WindowShouldClose())
    {
        const float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) player.x += speed * dt;
        if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) player.x -= speed * dt;
        if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) player.y += speed * dt;
        if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) player.y -= speed * dt;

        player.x = Clamp(player.x, radius, screenWidth - radius);
        player.y = Clamp(player.y, radius, screenHeight - radius);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(player, radius, MAROON);
            DrawText("WASD / arrow keys to move - ESC to quit", 20, 20, 20, DARKGRAY);
            DrawFPS(screenWidth - 100, 20);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
