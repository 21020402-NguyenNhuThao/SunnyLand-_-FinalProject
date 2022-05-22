#include "Food.h"
Food::Food()
{
   PosX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;

	PosY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT + 1) + ENEMY_MIN_HEIGHT;
    // PosY = 0;
    frame = 0;
}
void Food::Render(LTexture gCarrotTexture,SDL_Renderer* gRenderer, SDL_Rect* clip )
{
    gCarrotTexture.Render(PosX,PosY,gRenderer,clip);
}
void Food::Move(const int &acceleration)
{
    PosX += -(3 + acceleration);
	if (PosX + MAX_ENEMY_WIDTH < 0)
	{
		PosX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
        PosY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT + 1) + ENEMY_MIN_HEIGHT;
	}
}
void Food::Playing(LTexture gCarrotTexture, SDL_Renderer *gRenderer, 
    SDL_Rect gCarrotClips[], const int &acceleration)
{
    Move(acceleration);
    SDL_Rect *current_clips = &gCarrotClips[frame/FOOD_TOTAL_FRAME];
    Render(gCarrotTexture,gRenderer,current_clips);
    ControlFrame();
}
void Food::ControlFrame()
{
    frame++;
    if(frame/FOOD_TOTAL_FRAME >= FOOD_TOTAL_FRAME)
        frame = 0;
}