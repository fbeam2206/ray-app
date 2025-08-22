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
    Vector3 _vel;
    Vector3 _acc;

  public:
    void UpdatePos(){
      this->_pos.x += (0.5)*this->_acc.x*GetFrameTime()*GetFrameTime() + this->_vel.x*GetFrameTime(); 
      this->_pos.y += (0.5)*this->_acc.y*GetFrameTime()*GetFrameTime() + this->_vel.y*GetFrameTime(); 
      this->_pos.z += (0.5)*this->_acc.z*GetFrameTime()*GetFrameTime() + this->_vel.z*GetFrameTime(); 
    }

    void UpdateVel(){
      this->_vel.x += this->_acc.x*GetFrameTime();
      this->_vel.y += this->_acc.y*GetFrameTime();
      this->_vel.z += this->_acc.z*GetFrameTime();
    }

    void SetAcc(Vector3 acc){
      this->_acc.x = acc.x;
      this->_acc.y = acc.y;
      this->_acc.z = acc.z;
    }

    void SetInitPos(Vector3 pos){
      _pos = pos;
    }

    Vector3 GetPos(){
      return this->_pos;
    }

    Vector2 GetPos2D(){
      return {this->_pos.x, this->_pos.y};
    }
};