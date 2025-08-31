
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
#include "collision.h"


double Larger(double x1, double x2){
  return x1 * (x1 > x2)
    + x2 * (x2 >= x1);
}


double Smaller(double x1, double x2){
  return x1 * (x1 < x2)
    + x2 * (x2 <= x1);
}


void LeftClick(WorldState *state){
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    PointMass newMass = PointMass();
    state->IncCount();
      state->masses[state->GetObjCount() - 1] = newMass;
  }
}


bool Colliding(MassCollection m1, MassCollection m2){
  if (Larger(m1.massOne.GetPos().x, m1.massTwo.GetPos().x) >= Smaller(m2.massOne.GetPos().x, m2.massTwo.GetPos().x)){
    if (Larger(m1.massOne.GetPos().y, m1.massTwo.GetPos().y) >= Smaller(m2.massOne.GetPos().y, m2.massTwo.GetPos().y)) 
      {return 1;}
    else 
      {return 0;}
  }
  else 
    {return 0;}
}
