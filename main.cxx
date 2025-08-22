#include <stdio.h>
#include <string>
#include "src/class/winclass.h"

#if defined (_WIN32)
  #define PLATFORM_WINDOWS
#elif defined(__linux__)  
  #define PLATFORM_LINUX
#endif

#ifdef PLATFORM_WINDOWS
  #include "C:/msys64/mingw64/include/raylib.h"
#elif defined(PLATFORM_LINUX)
  #include <raylib.h>
#endif


int main(){

  Window mainWin; 
  mainWin.InitWin(800, 500, (char*)"Window");
  SetTargetFPS(60);

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Open", 0, 0, 24, RED);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}