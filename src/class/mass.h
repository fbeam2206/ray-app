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

class PointMass
{
  private:
    float _mass;
    Vector3 _pos; //Center of Mass
    Vector3 _vel;
    Vector3 _acc;

    void UpdatePos(){
      this->_pos += Vector3Add(Vector3Scale(this->_acc, (0.5)*GetFrameTime()*GetFrameTime()), Vector3Scale(this->_vel, GetFrameTime())); 
    }

    void UpdateVel(){
      this->_vel += Vector3Scale(this->_acc, GetFrameTime());
    }

  public:
    //-----Constructor-----//
    PointMass(){
      SetPos((Vector3){GetMousePosition().x, GetMousePosition().y, 0});

      SetVel((Vector3){0,0,0});

      SetAcc((Vector3){0,4,0});
      
      SetMass((double) 50);
      
    }

    //-----Updates-----//
    void UpdateValsAndDraw(){
      this->UpdateVel();
      this->UpdatePos();
      DrawCircleV(this->GetPos2D(), 15, RAYWHITE);
    }

    //-----Gets-----//
    Vector3 GetAcc(){
      return this->_acc;
    }
    Vector3 GetVel(){
      return this->_vel;
    }
    Vector3 GetPos(){
      return this->_pos;
    }
    Vector2 GetPos2D(){
      return {this->_pos.x, this->_pos.y};
    }
    float GetMass(){
      return this->_mass;
    }

    //-----Sets-----//
    void SetPos(Vector3 pos){
      this->_pos = pos;
    }
    void SetVel(Vector3 vel){
      this->_vel = vel;
    }
    void SetAcc(Vector3 acc){
      this->_acc = acc;
    }
    void SetMass(double mass){
      this->_mass = mass;
    }

    
    //-----Derivative-Attributes----//
    Vector3 GetMomentum(){
      return Vector3Scale(this->_vel, this->_mass);
    }
    
    PointMass CloseObjs(){
      PointMass massObjs[10];
      return massObjs[9];
  }
};


//-----------Two Point Masses-----------//
class MassCollection
{
public: 
  PointMass massOne;
  PointMass massTwo;

  Vector2 AABBx = {massOne.GetPos().x, massTwo.GetPos().x};
  Vector2 AABBy = {massOne.GetPos().y, massTwo.GetPos().y};
  Vector2 AABBz = {massOne.GetPos().z, massTwo.GetPos().z};

  Vector3 CoM = Vector3Scale(Vector3Add(massOne.GetPos(), massTwo.GetPos()), (float)0.5);
  

};

