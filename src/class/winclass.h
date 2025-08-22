#include "C:/msys64/mingw64/include/raylib.h"
#include <string>

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
      InitWindow(this->_width, this->_height, this->_name);
    }

};