#include "character.h"

#include "raymath.h"

Character::Character(int win_width, int win_height) {
    width = texture.width / max_frames;
    height = texture.height;

    knight_pos = Vector2{
        static_cast<float>(win_width) / 2.0f - scale * (0.5f * width),
        static_cast<float>(win_height) / 2.0f - scale * (0.5f * height)};
}

// void Character::setKnightPos(int win_width, int win_height) {
//     knight_pos = Vector2{win_width / 2.0f - 4.0f * (0.5f * width),
//                          win_height / 2.0f - 4.0f * (0.5f * height)};
// }

void Character::tick(float delta_time) {
    Vector2 direction{};
    world_pos_last_frame = world_pos;
    if (IsKeyDown(KEY_LEFT)) direction.x -= 1.0;
    if (IsKeyDown(KEY_RIGHT)) direction.x += 1.0;
    if (IsKeyDown(KEY_UP)) direction.y -= 1.0;
    if (IsKeyDown(KEY_DOWN)) direction.y += 1.0;
    if (Vector2Length(direction) != 0.0) {
        direction = Vector2Normalize(direction);
        direction = Vector2Scale(direction, speed);

        // set world_pos = world_pos + direction
        world_pos = Vector2Add(world_pos, direction);

        right_left = direction.x < 0.f ? -1.f : 1.f;
        texture = run;
    } else {
        texture = idle;
    }

    // update the character animation
    running_time += delta_time;
    if (running_time >= update_time) {
        running_time = 0;
        frame++;
        if (frame > max_frames) frame = 0;
    }

    // draw the character
    Rectangle source{frame * width, 0.f, right_left * width, height};
    Rectangle dest{knight_pos.x, knight_pos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

void Character::undoMovement() { world_pos = world_pos_last_frame; }