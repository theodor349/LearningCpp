
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Moving Shape");
    Vector2 position = { (float)screenWidth / 2, (float)screenHeight / 2 };
    const float scrollSpeed = 8;
    float rotation = 10;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) position.x -= 2.0f;
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) position.x += 2.0f;
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) position.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) position.y += 2.0f;

        rotation -= (GetMouseWheelMove() * scrollSpeed);
        if (rotation < 0) rotation = 360;
        else if (rotation > 360) rotation = 0;
        
        Rectangle rectangle = { position.x, position.y, 80, 80 };
        Vector2 rotationVector = { (float)rectangle.width / 2, (float)rectangle.height / 2 };

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawRectanglePro(rectangle, rotationVector, rotation, RED);
        //DrawCircle(position.x, position.y, 50, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

