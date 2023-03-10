#include "raylib.h"

class Character {
   public:
    Character(int win_width, int win_height);
    Vector2 getWorldPos() { return world_pos; }
    // void setKnightPos(int win_width, int win_height);
    void tick(float delta_time);
    void undoMovement();

   private:
    Texture2D texture = LoadTexture("./characters/knight_idle_spritesheet.png");
    Texture2D idle = LoadTexture("./characters/knight_idle_spritesheet.png");
    Texture2D run = LoadTexture("./characters/knight_run_spritesheet.png");
    Vector2 knight_pos{};
    Vector2 world_pos{};
    float right_left = 1.f;
    float update_time = 1.f / 12.f;
    float running_time = 0.f;
    int frame = 0;
    float max_frames = 6;
    float speed = 4.f;
    float width{};
    float height{};
    Vector2 world_pos_last_frame{};
    const float scale = 4.f;
};
