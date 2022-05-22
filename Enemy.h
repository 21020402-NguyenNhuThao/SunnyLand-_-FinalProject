#include "LTexture.h"
class Enemy 
{
private:
    int PosX, PosY;
    int type;
    int type2;
    
    int frame;
   
public:
    
    Enemy(int _type,int _type2 );
    ~Enemy();
    int getPosX(){
        return PosX;
    }
    int getPosY(){
        return PosY;
    }
    int getType(){
        return type;
    }
    int getType2()
    {
        return type2;
    }
    void Move(const int &acceleration);
    int GetSpeed(const int& acceleration){
        return ENEMY_SPEED + acceleration;
    }
    void Render(LTexture gEnemyTexture, SDL_Renderer* gRenderer, SDL_Rect* clip = nullptr);
    void Playing(LTexture gEnemyTexture,const int &acceleration,SDL_Renderer* gRenderer, SDL_Rect gEnemyClips[]);
    void ControlFrame(int TOTAL_FRAME);

};

