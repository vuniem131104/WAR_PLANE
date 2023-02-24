#ifndef common_h
#define common_h
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
using namespace std;
const int frame_per_second = 25;
const int screen_width = 1300;
const int screen_height = 700;
const int BG_WIDTH = 4800;
const int BG_HEIGHT = 600;
const int BOSS_WIDTH = 250;
const int BOSS_HEIGHT = 300;
namespace COMMONF{
    bool checkCollision(const SDL_Rect& object1, const SDL_Rect& object2);
    int Show_Menu(SDL_Renderer* g_menu, SDL_Renderer* screen, TTF_Font* font);
}

#endif 