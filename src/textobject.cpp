#include "textobject.h"

TextObject :: TextObject(){
    tWidth = 0;
    tHeight = 0;
    str_val = "";
    text_color.r = 255;
    text_color.g = 255;
    text_color.b = 255;
    texture_ = NULL;
}

TextObject :: ~TextObject(){
    
}
bool TextObject :: LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen){
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, str_val.c_str(), text_color);
    if(text_surface != NULL){
        texture_ = SDL_CreateTextureFromSurface(screen, text_surface);
        tWidth = text_surface->w;
        tHeight = text_surface->h;
        SDL_FreeSurface(text_surface);
    }
    return texture_ != NULL;
}

void TextObject :: free(){
    if(texture_ != NULL){
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

void TextObject :: setcolor(Uint8 red, Uint8 green, Uint8 blue){
    text_color.r = red;
    text_color.b = blue;
    text_color.g = green;
}

void TextObject :: setcolor(int type){
    if(type == RED_TEXT){
        SDL_Color color = {255, 0, 0};
        text_color = color;
    }else if(type == WHITE_TEXT){
        SDL_Color color = {255, 255, 255};
        text_color = color;
    }else{
        SDL_Color color = {0, 0, 0};
        text_color = color;
    }
}

void TextObject :: renderText(SDL_Renderer* screen, 
                int xp, 
                int yp, 
                SDL_Rect* clip, 
                double angle , SDL_Point* center, 
                SDL_RendererFlip flip)
{
    SDL_Rect renderVU = {xp, yp, tWidth, tHeight};
    if(clip != NULL){
        renderVU.w = clip->w;
        renderVU.h = clip->h;
    }
    SDL_RenderCopyEx(screen, texture_, clip, &renderVU, angle, center, flip);
}