
#if defined (_WIN32)
  #define PLATFORM_WINDOWS
#elif defined(__linux__)  
  #define PLATFORM_LINUX
#endif
#ifdef PLATFORM_WINDOWS
  #include "C:/msys64/ucrt64/include/raylib.h"
  #include "C:/msys64/ucrt64/include/raymath.h"
#elif defined(PLATFORM_LINUX)
  #include <raylib.h>
  #include <raymath.h>
#endif
#include "collision.h"



void LeftClick(WorldState *state){
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    PointMass newMass = PointMass();
    state->IncCount();
    state->masses.emplace_back(newMass);
  }
}


