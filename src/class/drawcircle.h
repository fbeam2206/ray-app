#if defined (_WIN32)
  #define PLATFORM_WINDOWS
#elif defined(__linux__)  
  #define PLATFORM_LINUX
#endif

#ifdef PLATFORM_WINDOWS
  #include "C:/msys64/usr/include/raylib.h"
  #include "C:/msys64/usr/include/raymath.h"
#elif defined(PLATFORM_LINUX)
  #include <raylib.h>
  #include <raymath.h>
#endif


Vector3 MoveInACircle(float* angle, float r){
    float z=0;//TODO
    float x = r * cos(*angle) + (400);
    float y = r * sin(*angle) + (250);
    
    *angle += 0.01f;  // Increment angle
    if (*angle >= 2 * PI) {
        *angle = 0;  // Reset after full circle
    }
    
    return (Vector3){x, y, z};
}
