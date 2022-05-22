#include "Character.h"
Character::Character(/* args */)
{
    PosX = SCREEN_WIDTH - 700;
    PosY = GROUND;
    frame = 0;
}

void Character::HandelEvent(SDL_Event &event, Mix_Chunk *gChunk)
{
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_SPACE)
        {
            if (on_ground())
            {
                status = JUMP;

                Mix_PlayChannel(-1, gChunk, 0);
            }
        }
    }
}
void Character::Move()
{
    if (status == JUMP && PosY >= 100)
    {
        PosY -= JUMP_SPEED;
    }
    if (PosY <= MAX_HEIGHT_JUMP)
    {
        status = FALL;
    }
    if (status == FALL && PosY < GROUND)
    {
        PosY += FALL_SPEED;
    }
}
void Character::Render(LTexture gCharacterTexture,
                       SDL_Rect *current_clips,
                       SDL_Renderer *render)
{
    gCharacterTexture.Render(PosX, PosY, render, current_clips);
}
void Character::Playing(LTexture gCharacterTexture,
             SDL_Rect gCharacterClips[2],
             SDL_Renderer *render)
{
    Move();
    SDL_Rect* current_clips = nullptr;
    if(this->on_ground())
    {
        current_clips = &gCharacterClips[frame / 8];
        Render(gCharacterTexture, current_clips, render);
    }
    else
    {
        current_clips = &gCharacterClips[0];
        Render(gCharacterTexture, current_clips, render);
    }
    ControlFrame();

}
void Character::ControlFrame()
{
    frame++;
    if (frame / 8 >= 8)
        frame = 0;
}