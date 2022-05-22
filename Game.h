#include "GameInit.h"
const std::string LAYER[LAYERS]{
    "imgs/background/background1.png",
    "imgs/background/background2.png",
    "imgs/background/background3.png",
    "imgs/background/background4.png",
    "imgs/background/background5.png",
    "imgs/background/background6.png"};
class Game
{
private:
    SDL_Window *gWindow = NULL;
    SDL_Renderer *gRenderer = NULL;
    float scrollingOff[6];

    LTexture gBackground[LAYERS];
    LTexture gBoardTexture;
    LTexture gCharacterTexture;
    LTexture gTreeTexture;
    LTexture gBeeTexture;
    LTexture gSlugTexture;
    LTexture gCarrotTexture;
    LTexture gBlood;
    LTexture gBloodTex;
    LTexture gYourScoreTexture;
    LTexture gHighestScoreTexture;
    LTexture gPlayButtonTexture;
    LTexture gHelpButtonTexture;
    LTexture gExitButtonTexture;
    LTexture gBackButtonTexture;
    LTexture gPauseButtonTexture;
    LTexture gContinueButtonTexture;
    LTexture gMenuTexture;
    LTexture gLoseTexture;
    LTexture gInstructionTexture;
    LTexture gScore;
    LTexture gHighScore;
    LTexture gStatusTexture;
    LTexture gStatusNormalTexture;
    LTexture gSoundTexture;

    SDL_Color textColor = {255, 165, 0};
    TTF_Font *gFont = nullptr;
    Mix_Music *gMusic = nullptr;
    Mix_Music *gMenuMusic = nullptr;
    Mix_Chunk *gClick = nullptr;
    Mix_Chunk *gJump = nullptr;
    Mix_Chunk *gLose = nullptr;
    Mix_Chunk *gEat = nullptr;
    Mix_Chunk *gMouseClick = nullptr;

    SDL_Rect gCharacterClips[CHA_LAYERS];
    SDL_Rect gTreeClips[ONGROUND_TOTAL_FRAME];
    SDL_Rect gBeeClips[ONAIR_TOTAL_FRAME];
    SDL_Rect gSlugClips[ONGROUND_TOTAL_FRAME];
    SDL_Rect gCarrotClips[FOOD_TOTAL_FRAME];
    SDL_Rect gPlayButton[BUTTON_TOTAL];
    SDL_Rect gHelpButton[BUTTON_TOTAL];
    SDL_Rect gExitButton[BUTTON_TOTAL];
    SDL_Rect gBackButton[BUTTON_TOTAL];
    SDL_Rect gPauseButton[BUTTON_TOTAL];
    SDL_Rect gContinueButton[BUTTON_TOTAL];
    SDL_Rect gPlayAgainButton[BUTTON_TOTAL];
    SDL_Rect gStatusHurt[2];
    SDL_Rect gStatusNormal[9];
    SDL_Rect gSoundButton[2];

    Button BACK_BUTTON,
        CONTINUE_BUTTON, EXIT_BUTTON,
        HELP_BUTTON, PAUSE_BUTTON,
        PLAY_BUTTON, SOUND_BUTTON;

    int timeplay = 0;
    int score = 0;

    int bloods = MAX_BLOOD;
    int eat = 0;
    int hurt = 0;

    int status_hurt_frame = 0;
    int status_normal_frame = 0;
    int acceleration = 0;

public:
    bool Quit_Menu;
    bool Play_Again;
    Game();
    ~Game()
    {
        close();
    }
    bool init();
    bool loadMedia();
    void close();
    void RenderMenu();
    void PlayAgain();
    // void Play();
    void ResetGame();
    void RenderStatus();
    void RenderEnviroment();
    void CheckInteractBetweenObject(Character &character, Food &food,
                                    Enemy &bee, Enemy &tree, Enemy &slug);
    void RenderObject(Character &character, Food &food,
                      Enemy &bee, Enemy &tree, Enemy &slug);
    void PlayMusic()
    {
        Mix_PlayMusic(gMusic, -1);
    }
};
