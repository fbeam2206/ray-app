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
#include "eventhandling.cxx"

void UpdateLoop(WorldState *mainState){
  
  LeftClick(mainState);
  for (int i = 0; i < mainState->GetObjCount() - 1; i++) {
    if (i < mainState->masses.size()){
    mainState->masses[i].UpdateValsAndDraw();
    }
  }
  CheckBroadCollision(mainState);

}
