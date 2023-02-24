#ifndef mainobject_h
#define mainobject_j


#include "common.h"
#include "baseobject.h"
#include "bulletobject.h"
class MainObject : public BaseObject{
	public:
	MainObject();
	~MainObject();
	void handleInput(SDL_Event e, SDL_Renderer* screen, Mix_Chunk* bullet_sound[3]);
	void handleBullet(SDL_Renderer* des);
	void set_v_bullet_list(vector<BulletObject*> v){
		v_bullet_list = v;
	}
	vector<BulletObject*> get_v_bullet_list(){
		return  v_bullet_list;
	}
	private:
	vector<BulletObject*> v_bullet_list;
};
#endif 