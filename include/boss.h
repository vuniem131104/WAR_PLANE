#ifndef boss_h
#define boss_h
#include "common.h"
#include "bulletobject.h"
#include "threatobject.h"
#include "baseobject.h"
class Boss : public ThreatObject{
    public:
    Boss();
    ~Boss();
    void khoi_tao_dan(BulletObject* p, SDL_Renderer* screen);
    void dan_ban(SDL_Renderer* screen, int x_b, int y_b);
    void handle_move_boss();
    private:
};


#endif // !