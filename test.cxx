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

  m1.massOne.SetPos(Vector3 {0,0,0});
  m1.massTwo.SetPos(Vector3 {100,100,0});

  std::cout << Larger(m1);

  return 0;
}
