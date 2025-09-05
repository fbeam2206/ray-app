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
#include <iostream>
#include <algorithm>
#include <vector>
#include "src/class/winclass.h"
#include "src/class/drawcircle.h"
#include "src/class/eventhandling.cxx"


int main(){
  MassCollection mass1, mass2, mass3;

  WorldState state;

  mass2.massOne.SetPos((Vector3){100, 100, 0});
  mass1.massOne.SetPos((Vector3){50, 100, 0});
  mass3.massOne.SetPos((Vector3){25, 100, 0});
  mass2.massTwo.SetPos((Vector3){100, 100, 0});
  mass1.massTwo.SetPos((Vector3){50, 100, 0});
  mass3.massTwo.SetPos((Vector3){25, 100, 0});

  state.masses.emplace_back(mass1);
  state.masses.emplace_back(mass2);
  state.masses.emplace_back(mass3);

  std::sort(state.masses.begin(), state.masses.end(), OrderByX);

  for(auto mass : state.masses){
    printf("%f \n", mass.massOne.GetPos().x);
  }



  return 0;
}
