
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
#include "src/class/winclass.h"
#include "src/class/drawcircle.h"
#include "src/class/update.cxx"
#include <ctime>


////////////////////////////
////////////TODO////////////
////////////////////////////
//                        //
// 1)Momentum & Collision //
//    of Mass Collections //
//                        //
////////////////////////////

int main(){

  srand(static_cast<unsigned int>(time(nullptr)));
  
  WorldState mainState;
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

      UpdateLoop(&mainState);
      DrawCircleV(test.GetPos2D(), 15, RAYWHITE);
      //test.SetPos(MoveInACircle(&angle, r));
      //sprintf(position, "pos-x:%.01f", mainState.masses[0].GetPos2D().x);
      //DrawText(position, 0, 0, 21, RED);
      
    //----------------------//
    
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
