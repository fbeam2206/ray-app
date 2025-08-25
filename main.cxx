#include "src/class/mass.h"
#include "src/class/winclass.h"
#include "src/class/drawcircle.h"

#if defined (_WIN32)
  #define PLATFORM_WINDOWS
#elif defined(__linux__)  
  #define PLATFORM_LINUX
#endif

#ifdef PLATFORM_WINDOWS
  #include "C:/msys64/mingw64/include/raylib.h"
  #include "C:/msys64/mingw64/include/raymath.h"
#elif defined(PLATFORM_LINUX)
  #include <raylib.h>
  #include <raymath.h>
#endif
#include <iostream>

////////////////////////////
////////////TODO////////////
////////////////////////////
//                        //
// 1)Momentum & Collision //
//                        //
////////////////////////////

int main(){

  Mass masses[100];
  Mass test;
  Window mainWin; 
  char position[32];
  mainWin.InitWin(800, 500, (char*)"Window");
  float angle, r;
  r = 100.0;

  test.SetPos(Vector3{(float)mainWin.GetWidth()/2, (float)mainWin.GetHeight()/2, 0});
  test.SetAcc(Vector3 {2, 2, 0});

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircleV(test.GetPos2D(), 15, RAYWHITE);
    test.SetPos(MoveInACircle(&angle, r));
    sprintf(position, "pos-x:%.01f", test.GetPos2D().x);
    DrawText(position, 0, 0, 21, RED);
    //DrawPixelV(Vector2Add(MoveInACircle(&angle, r), {400, 250}), RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
