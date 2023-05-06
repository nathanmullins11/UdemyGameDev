#include "raylib.h"

int dasher(void)
{
  // variables for window
  const int Windowwidth = 512;
  const int Windowheight = 380;
  // create window
  InitWindow(Windowwidth,Windowheight,"Dapper Dasher");

  // rectangle dimensions
  const int rectWidth = 50;
  const int rectHeight = 80;

  int posY = Windowheight - rectHeight;
  int velocity = 0; // pixels per frame
  const int gravity = 1; // pixels/frame^2

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);\

    // perform ground check
    if(posY >= Windowheight - rectHeight)
    {
      // rect on ground
      velocity = 0;
    }
    else
    {
      // rect in air
      velocity += gravity;
    }

    if(IsKeyPressed(KEY_SPACE))
    {
      velocity -= 10;
    }

    // update rect position
    posY += velocity;

    DrawRectangle(Windowwidth/2, posY, rectWidth, rectHeight, BLUE);
    EndDrawing();
  }
  
  CloseWindow();
  
}