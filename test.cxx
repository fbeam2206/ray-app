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


int main(){
  MassCollection m1;
  MassCollection m2;

  m1.massOne.SetPos(Vector3 {0,0,0});
  m1.massTwo.SetPos(Vector3 {100,100,0});
  m1.massOne.SetVel(Vector3 {1,1,0});
  m1.massTwo.SetVel(Vector3 {100,100,0});

  m2.massOne.SetPos(Vector3 {95,100,0});
  m2.massTwo.SetPos(Vector3 {115,115,0});

  std::cout << "Colliding: " << Colliding(m1, m2);

  //std::cout << "Larger: " << Larger(m1.massOne.GetPos().x, m1.massTwo.GetPos().x) << "\n";
  //std::cout << "Smaller: " << Smaller(m1.massOne.GetPos().x, m1.massTwo.GetPos().x) << "\n";

  return 0;
}
