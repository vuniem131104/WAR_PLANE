#include "explosion.h"

Explosion :: Explosion(){
    frame = 0;
    frame_height = 0;
    frame_width = 0;
}

Explosion :: ~Explosion(){
    
}

bool Explosion :: loadFromFile(string path, SDL_Renderer* screen){
    bool res = BaseObject :: loadFromFile(path, screen);
    if(res){
        frame_width = rect_.w / 4;
        frame_height = rect_.h;
    }
    return res;
}

void Explosion :: setclip(){
    if(frame_width > 0 && frame_height > 0){
        clip[0].x = 0;
        clip[0].y = 0;
        clip[0].w = exp_width;
        clip[0].h = exp_height;
        clip[1].x = exp_width;
        clip[1].y = 0;
        clip[1].w = exp_width;
        clip[1].h = exp_height;
        clip[2].x = exp_width * 2;
        clip[2].y = 0;
        clip[2].w = exp_width;
        clip[2].h = exp_height;
        clip[3].x = exp_width * 3;
        clip[3].y = 0;
        clip[3].w = exp_width;
        clip[3].h = exp_height;
    }
}

void Explosion :: showEXP(SDL_Renderer* screen){
    SDL_Rect* currentclip = &clip[frame];
    SDL_Rect vu = {rect_.x, rect_.y, frame_width, frame_height};
    if(currentclip != NULL){
        vu.w = currentclip->w;
        vu.h = currentclip->h;
    }
    SDL_RenderCopy(screen, mTexture, currentclip, &vu);
}