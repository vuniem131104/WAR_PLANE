#ifndef bulletobject_h
#define bulletobject_h

#include "common.h"
#include "baseobject.h"

class BulletObject : public BaseObject{
	public:
	BulletObject();
	~BulletObject();

    enum Bulletdir{
        DIR_RIGHT = 20,
        DIR_RIGHT_DOWN = 21,
        DIR_RIGHT_UP = 22
    };

	void set_x(const int& x){
		x_val = x;
	}
	int get_x(){
		return x_val;
	}
	void set_y(const int& y){
		y_val = y;
	}
	int get_y(){
		return y_val;
	}
	void set_is_move(bool ismove){
		is_move = ismove;
	}
	bool get_is_move(){
		return is_move;
	}
    void set_buller_dir(unsigned int b_l){
        bullet_dir = b_l;
    }
    unsigned int get_bullet_dir(){
        return bullet_dir;
    }
	void handlemove(int x_b, int y_b);
    void handlemove_right_to_left(int speed);
	private:
	int x_val;
	int y_val;
	bool is_move;
    unsigned int bullet_dir;
};


#endif // !