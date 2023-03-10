#include "character.h"
#include "raylib.h"
#include "raymath.h"

int main() {
    const int window_width = 384;
    const int window_height = 384;

    InitWindow(window_width, window_height, "Classy Clash");

    Texture2D map = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
    Vector2 map_pos{0.0, 0.0};
    float speed = 4.0f;

    Character knight = Character(window_width, window_height);
    // knight.setKnightPos(window_width, window_height);
    const float scale = 4.f;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        float dt = GetFrameTime();

        // draw the map
        map_pos = Vector2Scale(knight.getWorldPos(), -1.f);
        DrawTextureEx(map, map_pos, 0.0, scale, WHITE);

        knight.tick(dt);
        if (knight.getWorldPos().x < 0.f || knight.getWorldPos().y < 0 ||
            knight.getWorldPos().x + window_width > map.width * scale ||
            knight.getWorldPos().y + window_height > map.height * scale) {
            knight.undoMovement();
        }

        EndDrawing();
    }

    UnloadTexture(map);
    // UnloadTexture(knight);
    // UnloadTexture(knight_idle);
    // UnloadTexture(knight_run);
    CloseWindow();

    return 0;
}