#if defined (_WIN32)
  #define PLATFORM_WINDOWS
#elif defined(__linux__)  
  #define PLATFORM_LINUX
#endif

#ifdef PLATFORM_WINDOWS
  #include "C:/msys64/mingw64/include/raylib.h"
#elif defined(PLATFORM_LINUX)
  #include <raylib.h>
#endif

class Mass
{
  private:
    double _mass;
    Vector3 _pos;

  public:
    
};