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
#endif

Vector2 DrawInACircle(double x, double r, double* i, double* j){
  double y;

  x = r*cos((r - *i)/r);
  y = sqrt(r*r - x*x);

  *i++;
  *j++;

  if(*j >= r){
    *i--;
  }
  else if(*j >= r*2){
    *j = 0;
  }

  return (Vector2){x, y};
}