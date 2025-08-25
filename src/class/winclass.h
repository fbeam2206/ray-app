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

class Window
{
  private:
    int _width;
    int _height;
    char* _name;

  public:
    void SetWidth(int width){
      _width = width;
    }

    int GetWidth(){
      return _width;
    }

    void SetHeight(int height){
      _height = height;
    }

    int GetHeight(){
      return _height;
    }

    void SetName(char* name){
      _name = name;
    }

    char* GetName(){
      return _name;
    }

    void InitWin(int width, int height, char* name){
      _width = width;
      _height = height;
      _name = name;
      SetTargetFPS(60);
      InitWindow(this->_width, this->_height, this->_name);
    }
};