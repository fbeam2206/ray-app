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
  #include <bits/stdc++.h>
#endif
#include <iostream>
#include "datastructs.h"
#include <algorithm>

char comp[50];

bool CompareByX(PointMass& m1, PointMass& m2){
  return m1.GetPos().x > m2.GetPos().x;
}

// Binary Tree - Smarter Space Partitioning
void CheckBroadCollision(WorldState *state){
  int currentObjCount = state->GetObjCount();

  std::sort(state->masses.begin(), state->masses.end(), CompareByX);
  for(auto i = state->masses.begin(); i != state->masses.end(); ++i){
    sprintf(comp, "x[0]: %.01f", i->GetPos().x);
    DrawText(comp, i->GetPos().x, 21, 21, RED);
  } 

  if (currentObjCount > 2)
  {
    if (state->masses.front().GetPos().x < state->masses.back().GetPos().x)
    { 
      for(auto i = state->masses.begin(); i != state->masses.end(); ++i)
      {
        sprintf(comp, "x[0]: %.01f", i->GetPos().x);
        DrawText(comp, i->GetPos().x, 21, 21, RED);
      }
    }
    else
    {
      DrawText("Error", 0, 0, 21, RED);
      for(auto i = state->masses.begin(); i != state->masses.end(); ++i)
      {
        sprintf(comp, "x[0]: %.01f", i->GetPos().x);
        DrawText(comp, i->GetPos().x, 21, 21, RED);
      }
    }
  }


  //for (auto &PointMass : state->masses){
  //  std::cout << PointMass.GetPos().x;
  //}
/*
  for(;;){
    // CountObjectsInSpace
    
    //if(count <= 2) {break;}

    // OrderObjectsByXVal
    
    // SplitObjectsByXVal
    
  }
  */
}

// Change in to pass an array of Mass so can do # arbitary number of times
void CollisionElas(PointMass* mass1, PointMass* mass2){ 

  Vector3 SumMomentum = Vector3Add(mass1->GetMomentum(), mass2->GetMomentum());

  mass1->SetVel( Vector3Add( Vector3Scale( mass1->GetVel(), (mass1->GetMass() - mass2->GetMass()) / (mass1->GetMass() + mass2->GetMass())) , Vector3Scale(mass2->GetVel() , (2*mass2->GetMass() / (mass1->GetMass() + mass2->GetMass()) ) ) ) );
  mass2->SetVel( Vector3Add( Vector3Scale( mass2->GetVel(), (mass2->GetMass() - mass1->GetMass()) / (mass2->GetMass() + mass1->GetMass())) , Vector3Scale(mass1->GetVel() , (2*mass1->GetMass() / (mass2->GetMass() + mass1->GetMass()) ) ) ) );
}
