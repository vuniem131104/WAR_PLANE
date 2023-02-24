#ifndef textobject_h
#define textobject_h
#include "common.h"
class TextObject{
    public:
    enum TextColor{
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2
    };
    TextObject();
    ~TextObject();
    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
    void free();
    void setcolor(Uint8 red, Uint8 green, Uint8 blue);
    void setcolor(int type);
    void renderText(SDL_Renderer* screen, 
                    int xp, 
                    int yp, 
                    SDL_Rect* clip = NULL, 
                    double angle = 0.0, SDL_Point* center = NULL, 
                    SDL_RendererFlip = SDL_FLIP_NONE);
    int GetWidth(){
        return tWidth;
    }
    int GetHeight(){
        return tHeight;
    }
    void setText(string text){
        str_val = text;
    }
    string GetText(){
        return str_val;
    }
    private:
    string str_val;
    SDL_Color text_color;
    SDL_Texture* texture_;
    int tWidth;
    int tHeight;
};

#endif // !