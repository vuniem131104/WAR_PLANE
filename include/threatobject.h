#ifndef threatobject_h
#define threatobject_h
#include "baseobject.h"
#include "common.h"
#include "bulletobject.h"
class ThreatObject : public BaseObject{
	public:
	ThreatObject();
	~ThreatObject();
	void HandleMove(int x_b, int y_b);
	void set_X(const int& val){
		x_val = val;
	}
	void set_Y(int val){
		y_val = val;
	}
	int get_X(){
		return x_val;
	}
	int get_Y(){
		return y_val;
	}
	vector<BulletObject*> getBullet(){
		return p_bullet_list;
	}
	void setBullet(vector<BulletObject*> p){
		p_bullet_list = p;
	}
	void initBullet(BulletObject* p_b, SDL_Renderer* screen);
	void makeBullet(SDL_Renderer* screen, int x_b, int y_b);
	static int dem;
	protected:
	vector<BulletObject*> p_bullet_list;
	int x_val;
	int y_val;
};

#endif // !