#include <stdio.h>
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
#endif


int main(){

  Mass test;
  Window mainWin; 
  mainWin.InitWin(800, 500, (char*)"Window");
  float angle, r;
  r = 100.0;

  test.SetInitPos(Vector3{(float)mainWin.GetWidth()/2, (float)mainWin.GetHeight()/2, 0});
  test.SetAcc(Vector3 {1, 1, 0});


  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Open", 0, 0, 24, RED);
    test.UpdateVel();
    test.UpdatePos();
    DrawPixelV(test.GetPos2D(), RAYWHITE);
    //DrawPixelV(Vector2Add(MoveInACircle(&angle, r), {400, 250}), RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}