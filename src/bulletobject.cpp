#include "bulletobject.h"

void BulletObject :: handlemove(int x_b, int y_b){
    if(bullet_dir == DIR_RIGHT){
        rect_.x += x_val;
        if(rect_.x > x_b){
            is_move = false;
        }
    }else if(bullet_dir == DIR_RIGHT_DOWN){
        rect_.x += x_val;
        rect_.y += 20;
        if(rect_.x < 0 || rect_.y > screen_height){
            is_move = false;
        }
    }else{
        rect_.x += x_val;
        rect_.y -= 20;
        if(rect_.x < 0 || rect_.y < 0){
            is_move = false;
        }
    }
}

BulletObject :: BulletObject(){
	x_val = 0;
	y_val = 0;
	is_move = false;
}

BulletObject :: ~BulletObject(){
	free();
}

void BulletObject :: handlemove_right_to_left(int speed){
    rect_.x -= speed;
    if(rect_.x < 0){
        is_move = false;
    }
}