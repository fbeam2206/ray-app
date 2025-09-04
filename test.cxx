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
  MassCollection m1;
  MassCollection m2;

  PointMass mass1;
  PointMass mass2;

  mass1.SetPos((Vector3) {100, 100, 0});
  mass1.SetPos((Vector3) {50, 100, 0});

  m1.massOne.SetPos(Vector3 {0,0,0});
  m1.massTwo.SetPos(Vector3 {100,100,0});
  m1.massOne.SetVel(Vector3 {1,1,0});
  m1.massTwo.SetVel(Vector3 {100,100,0});

  m2.massOne.SetPos(Vector3 {95,100,0});
  m2.massTwo.SetPos(Vector3 {115,115,0});

  std::cout << "Colliding: " << Colliding(m1, m2);

  WorldState state;

  state.masses.emplace_back(mass1);
  state.masses.emplace_back(mass2);

  //state.masses[0].SetPos((Vector3) {100, 100,  0});
  //state.masses[1].SetPos((Vector3) {50, 100,  0});

  std::sort(state.masses.begin(), state.masses.end(), CompareByX);

  for(auto mass : state.masses){
    printf("%f \n", mass.GetPos().x);
  }

  //std::cout << "Larger: " << Larger(m1.massOne.GetPos().x, m1.massTwo.GetPos().x) << "\n";
  //std::cout << "Smaller: " << Smaller(m1.massOne.GetPos().x, m1.massTwo.GetPos().x) << "\n";

  return 0;
}
