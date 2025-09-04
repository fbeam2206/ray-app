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
  #include <bits/stdc++.h>
#endif
#include <iostream>
#include "datastructs.h"
#include <algorithm>

char comp[50];

bool OrderByX(PointMass& m1, PointMass& m2){
  return m1.GetPos().x < m2.GetPos().x;
}

int FindMedian(std::vector<PointMass> *masses){
  if (masses->size() % 2 != 0)
  {
    return masses->size()/2 + 1;  
  }
  else 
  {
    return masses->size()/2;  
  }
}

void recursive(std::vector<PointMass> *masses, std::vector<std::vector<PointMass>> *massVec){
  if(masses->size() > 2)
  {
    for(int i = 0; i < FindMedian(masses); ++i)
    {
      masses[i];
    }
    
  }
}

std::vector<std::vector<PointMass>> DivideVec(std::vector<PointMass> *masses){
  int median = FindMedian(masses);
  std::vector<std::vector<PointMass>> chunks;
  std::vector<PointMass> splitVec;

  for (int j=0; j<masses->size(); j=j+2){
    chunks.emplace_back(masses[j], masses[j+1]);
  }

  //for(int j=0; j < masses->size(); ++j)
  //{
  //  PointMass front_element = masses->front();
  //  masses->erase(masses->begin());
  //  splitVec.push_back(front_element);
  //}

  return chunks;
}

// Binary Tree - Smarter Space Partitioning
void CheckBroadCollision(WorldState *state){
  int j = 0;
  
  // SORTING
    std::sort(state->masses.begin(), state->masses.end(), OrderByX);

  // SPLITTING
    std::vector<std::vector<PointMass>> chunks = DivideVec(&state->masses);

  // Checking for Overlap 
  for(int i=0; i < chunks.size(); ++i)
    for(int k=0; k < 2; ++k)
    if(Colliding(chunks[i][k], chunks[i][k+1]))

  for(auto i = state->masses.begin(); i != state->masses.end(); ++i, ++j){
    sprintf(comp, "x[%d]: %.01f", j, i->GetPos().x);
    DrawText(comp, i->GetPos().x, i->GetPos().y - 10, 21, RED);
  } 

  j = 0;

}

// Change in to pass an array of Mass so can do # arbitary number of times
void CollisionElas(PointMass* mass1, PointMass* mass2){ 

  Vector3 SumMomentum = Vector3Add(mass1->GetMomentum(), mass2->GetMomentum());

  mass1->SetVel( Vector3Add( Vector3Scale( mass1->GetVel(), (mass1->GetMass() - mass2->GetMass()) / (mass1->GetMass() + mass2->GetMass())) , Vector3Scale(mass2->GetVel() , (2*mass2->GetMass() / (mass1->GetMass() + mass2->GetMass()) ) ) ) );
  mass2->SetVel( Vector3Add( Vector3Scale( mass2->GetVel(), (mass2->GetMass() - mass1->GetMass()) / (mass2->GetMass() + mass1->GetMass())) , Vector3Scale(mass1->GetVel() , (2*mass1->GetMass() / (mass2->GetMass() + mass1->GetMass()) ) ) ) );
}
