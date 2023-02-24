#include "threatobject.h"
#include "bulletobject.h"
ThreatObject :: ThreatObject(){
	rect_.x = screen_width;
	rect_.y = 0;
	rect_.w = 80;
	rect_.h = 40;
	x_val = 0;
	y_val = 0;
}

ThreatObject :: ~ThreatObject(){
	free();
}

void ThreatObject :: HandleMove(int x_b, int y_b){
	rect_.x -= x_val;
	if(rect_.x < 0){
        dem++;
		rect_.x = screen_width;
		int rand_y = 45 + rand()%400;
		if(rand_y > screen_height - 200)
		rand_y = screen_height * 0.3;
		rect_.y = rand_y;
	}
}

void ThreatObject :: initBullet(BulletObject* p_b, SDL_Renderer* screen){
    if(p_b){
        bool res = p_b->loadFromFile("res/bl3.png", screen);
        if(res){
            p_b->setRect(rect_.x, rect_.y + 20);
            p_bullet_list.push_back(p_b);
        }
    }
}

void ThreatObject :: makeBullet(SDL_Renderer* screen, int x_b, int y_b){
    for(unsigned int i = 0; i < p_bullet_list.size(); i++){
        BulletObject* p_bullet = p_bullet_list.at(i);
        if(p_bullet){
            if(p_bullet->get_is_move() == true){
                p_bullet->render(screen, NULL);
                p_bullet->handlemove_right_to_left(24);
            }else{
                p_bullet->set_is_move(true);
                p_bullet->setRect(rect_.x, rect_.y + 20);
            }
        }
    }
}

int ThreatObject :: dem = 0;