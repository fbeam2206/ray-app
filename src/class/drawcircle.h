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


Vector2 MoveInACircle(float* angle, float r) {
    float x = r * cos(*angle);
    float y = r * sin(*angle);
    
    *angle += 0.01f;  // Increment angle
    if (*angle >= 2 * PI) {
        *angle = 0;  // Reset after full circle
    }
    
    return (Vector2){x, y};
}