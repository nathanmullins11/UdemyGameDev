#include "raylib.h"
#include "dapper-dasher/dasher.cpp"

int axe(void)
{
  int width = 800;
  int height = 450;
  InitWindow(width,height,"Axe Game");

  // circle coordinates
  double circlex = 200;
  double circley = 200; 
  int radius_circle = 25;
  // cicrle edges
  int l_circle_x = circlex - radius_circle;
  int r_circle_x = circlex + radius_circle;
  int u_circle_y = circley - radius_circle;
  int b_circle_y = circley + radius_circle;

  // square coordinates/size
  int axe_x = 400;
  int axe_y = 0;
  double axe_length = 50;
  //axe/square edges
  int l_axe_x = axe_x;
  int r_axe_x = axe_x + axe_length;
  int u_axe_y = axe_y;
  int b_axe_y = axe_y + axe_length;

  int direction = 10;

  // val for collision
  bool collision_with_axe = ((b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x));

  SetTargetFPS(60);
  while (!WindowShouldClose()) // window should close returns true if x icon or esc key is hit
  {
    BeginDrawing(); // setup
    ClearBackground(WHITE); // clears canvas, prevents screen from flickering
    
    if(collision_with_axe) {
      DrawText("Game Over!", 400, 200, 20, RED);
    }
    else {
      // update the edges
      l_circle_x = circlex - radius_circle;
      r_circle_x = circlex + radius_circle;
      u_circle_y = circley - radius_circle;
      b_circle_y = circley + radius_circle;
      l_axe_x = axe_x;
      r_axe_x = axe_x + axe_length;
      u_axe_y = axe_y;
      b_axe_y = axe_y + axe_length;

      // check for collision
      collision_with_axe = ((b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x));

      // game loging begins
      DrawCircle(circlex,circley,radius_circle,BLUE); // circle in middle of screen
      DrawRectangle(axe_x,axe_y,axe_length,axe_length,RED);

      // move the axe (square)
      axe_y += direction;
      if(axe_y >= height || axe_y < 0)
      {
        // allows axe to wrap back around screen
        direction = -direction;
      }

      if(IsKeyDown(KEY_RIGHT) && (circlex < width))
      {
        circlex += 10;
      }
      if(IsKeyDown(KEY_LEFT) && (circlex > 0))
      {
        circlex -= 10;
      }
      if(IsKeyDown(KEY_DOWN) && (circley < height))
      {
        circley += 10;
      }
      if(IsKeyDown(KEY_UP) && (circley > 0))
      {
        circley -= 10;
      }
    }
    // game logic ends
    EndDrawing(); // teardown
  }

}

int main() {
  // axe();

  dasher();

}