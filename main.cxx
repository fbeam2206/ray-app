
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
#include "src/class/winclass.h"
#include "src/class/drawcircle.h"
#include "src/class/eventhandling.cxx"

////////////////////////////
////////////TODO////////////
////////////////////////////
//                        //
// 1)Momentum & Collision //
//    of Mass Collections //
//                        //
////////////////////////////

int main(){

  PointMass masses[100];
  int massCount;
  PointMass test;
  Window mainWin; 
  char position[32];
  mainWin.InitWin(800, 500, (char*)"Window");
  float angle, r;
  r = 100.0;

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    //----------------------//

      LeftClick(masses, &massCount);
      for (int i = 0; i < 100; i++) {
        masses[i].UpdateValsAndDraw();
      }

      DrawCircleV(test.GetPos2D(), 15, RAYWHITE);
      test.SetPos(MoveInACircle(&angle, r));

      
    //----------------------//
    sprintf(position, "pos-x:%.01f", test.GetPos2D().x);
    DrawText(position, 0, 0, 21, RED);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
