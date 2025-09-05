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

//char comp[50];


double Larger(double x1, double x2){
  return x1 * (x1 > x2)
    + x2 * (x2 >= x1);
}

double Smaller(double x1, double x2){
  return x1 * (x1 < x2)
    + x2 * (x2 <= x1);
}

bool OrderByX(MassCollection& m1, MassCollection& m2){
  return m1.massOne.GetPos().x < m2.massOne.GetPos().x;
}

int FindMedian(std::vector<MassCollection> *masses){
  if (masses->size() % 2 != 0)
  {
    return masses->size()/2 + 1;  
  }
  else 
  {
    return masses->size()/2;  
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

std::vector<std::vector<MassCollection>> DivideVec(std::vector<MassCollection> *masses){
  std::vector<std::vector<MassCollection>> chunks;
  std::vector<PointMass> splitVec;

  //for (int j=0, i=0; j<masses->size(); j=j+2, ++i){
  //  chunks[i].emplace_back(masses[j], masses[j+1]);
  //}
  
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
    std::vector<std::vector<MassCollection>> chunks = DivideVec(&state->masses);

  // Checking for Overlap 
  for(int i=0; i < chunks.size(); ++i){
    if(Colliding(chunks[i][0], chunks[i][1]))
    {
      printf("Colliding: %f", chunks[i][1].massOne.GetPos().x);
    }
  }

  //for(auto i = state->masses.begin(); i != state->masses.end(); ++i, ++j){
  //  sprintf(comp, "x[%d]: %.01f", j, i->GetPos().x);
  //  DrawText(comp, i->GetPos().x, i->GetPos().y - 10, 21, RED);
  //} 

  j = 0;

}

// Change in to pass an array of Mass so can do # arbitary number of times
void CollisionElas(PointMass* mass1, PointMass* mass2){ 

  Vector3 SumMomentum = Vector3Add(mass1->GetMomentum(), mass2->GetMomentum());

  mass1->SetVel( Vector3Add( Vector3Scale( mass1->GetVel(), (mass1->GetMass() - mass2->GetMass()) / (mass1->GetMass() + mass2->GetMass())) , Vector3Scale(mass2->GetVel() , (2*mass2->GetMass() / (mass1->GetMass() + mass2->GetMass()) ) ) ) );
  mass2->SetVel( Vector3Add( Vector3Scale( mass2->GetVel(), (mass2->GetMass() - mass1->GetMass()) / (mass2->GetMass() + mass1->GetMass())) , Vector3Scale(mass1->GetVel() , (2*mass1->GetMass() / (mass2->GetMass() + mass1->GetMass()) ) ) ) );
}


