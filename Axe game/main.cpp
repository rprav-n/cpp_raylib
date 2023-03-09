#include "raylib.h"

/* Header files (.h)
    <> - C++ std lib, built-in - Don't need to type .h for std lib
    "" - External lib
*/

int main() {
    // window dimensions
    int width = 800;
    int height = 450;
    InitWindow(width, height, "Hello world");

    // circle coordinates
    int circle_x = 100;
    int circle_y = height / 2;
    int circle_radius = 25;

    // circle edges
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    // axe coordinates
    int axe_x = 400;
    int axe_y = 0;
    int axe_vel = 5;
    int axe_length = 50;

    // axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;

    bool collision_with_axe = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins

        if (collision_with_axe) {
            DrawText("Game Over!", 400, 200, 20, RED);
        } else {
            // update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // move the axe
            axe_y += axe_vel;
            if (axe_y + axe_length == height || axe_y == 0) {
                axe_vel *= -1;
            }

            if (IsKeyDown(KEY_D) && circle_x + circle_radius < width) {
                circle_x += 5;
            }
            if (IsKeyDown(KEY_A) && circle_x - circle_radius > 0) {
                circle_x -= 5;
            }

            if (r_axe_x >= l_circle_x && l_axe_x <= r_circle_x &&
                b_axe_y >= u_circle_y && u_axe_y <= b_circle_y) {
                collision_with_axe = true;
            }

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
        }

        // Game logic ends
        EndDrawing();
    }

    CloseWindow();

    return 0;
}