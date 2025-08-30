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
  #include "mass.h"
#endif


// Change in to pass an array of Mass so can do # arbitary number of times
void CollisionElas(PointMass* mass1, PointMass* mass2){ 

  Vector3 SumMomentum = Vector3Add(mass1->GetMomentum(), mass2->GetMomentum());

  mass1->SetVel( Vector3Add( Vector3Scale( mass1->GetVel(), (mass1->GetMass() - mass2->GetMass()) / (mass1->GetMass() + mass2->GetMass())) , Vector3Scale(mass2->GetVel() , (2*mass2->GetMass() / (mass1->GetMass() + mass2->GetMass()) ) ) ) );
  mass2->SetVel( Vector3Add( Vector3Scale( mass2->GetVel(), (mass2->GetMass() - mass1->GetMass()) / (mass2->GetMass() + mass1->GetMass())) , Vector3Scale(mass1->GetVel() , (2*mass1->GetMass() / (mass2->GetMass() + mass1->GetMass()) ) ) ) );
}
