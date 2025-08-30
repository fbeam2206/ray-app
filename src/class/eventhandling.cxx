
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
#include "mass.h"

void LeftClick(PointMass array[], int* count){
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    PointMass newMass = PointMass();
    (*count)++;
    array[*count] = newMass;
  }
}

bool Colliding(MassCollection m1, MassCollection m2){
  if (m1.massTwo.GetPos().x > m2.massOne.GetPos().x){
    if (m1.massTwo.GetPos().y > m2.massOne.GetPos().y)
      {return 1;}
    else {return 0;}
  }
  else {return 0;}
}

double Larger(MassCollection m1){
  return m1.massOne.GetPos().x * (m1.massOne.GetPos().x > m1.massTwo.GetPos().x)
    + m1.massTwo.GetPos().x * (m1.massTwo.GetPos().x >= m1.massOne.GetPos().x);
}
