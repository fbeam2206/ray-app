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
#include <vector>
#include "mass.h"
#include <array>

class Node {
public:
  double data;
  Node *left, *right;
  Node(double x){
    data = x;
    left = nullptr;
    right = nullptr;
  }
};

class WorldState {
private:
  int _objCount;

public:

  std::vector<PointMass> masses;
  
  /*PointMass *GetArray(){
    PointMass* array = (PointMass*)MemAlloc(20 * sizeof(PointMass));
    return array;
  }*/

  void IncCount(){
    this->_objCount++;
  }
  void DecCount(){
    this->_objCount--;
  }
  int GetObjCount(){
    return this->_objCount;
  }
};
