#ifndef explosion_h
#define explosion_h
#include "common.h"
#include "baseobject.h"
const int exp_width = 165;
const int exp_height = 165;
class Explosion : public BaseObject{
    public:
    Explosion();
    ~Explosion();
    void setFrame(int fr){
        frame = fr;
    }
    void setclip();
    void showEXP(SDL_Renderer* screen);
    virtual bool loadFromFile(string path, SDL_Renderer* screen); 
    int getW(){
        return frame_width;
    }
    int getH(){
        return frame_height;
    }
    private:
    int frame;
    int frame_height;
    int frame_width;
    SDL_Rect clip[4];
};

#endif // !