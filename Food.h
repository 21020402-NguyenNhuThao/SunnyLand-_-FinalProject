#include "Ltexture.h"
class Food 
{
private:
    int PosX, PosY;
    int frame;

public:
    Food(/* args */);
    ~Food()
    {

    }
    int getPosX()
    {
        return PosX;
    }
    int getPosY()
    {
        return PosY;
    }
    void Disappear()
    {
        PosY = 500;
    }
    void Render(LTexture gCarrotTexture,SDL_Renderer* gRenderer, SDL_Rect* clip = nullptr);
    void Move(const int &acceleration);
    void Playing(LTexture gCarrotTexture, SDL_Renderer *gRenderer, 
    SDL_Rect gCarrotClips[], const int &acceleration);
    void ControlFrame();
};

