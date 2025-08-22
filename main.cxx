#include <stdio.h>
#include "C:/msys64/mingw64/include/raylib.h"
#include <string>
#include "src/class/winclass.h"

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