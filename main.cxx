#include <stdio.h>
#include <string>
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

  Window mainWin; 
  mainWin.InitWin(800, 500, (char*)"Window");
  double x, r;
  double i, j;
  x = 0; i = 0; j = 0;
  r = 100.0;

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Open", 0, 0, 24, RED);
    DrawPixelV(Vector2Add(DrawInACircle(x, r, &i, &j), {400, 250}), RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}