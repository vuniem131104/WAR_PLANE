#include "mainobject.h"

MainObject :: MainObject(){
	rect_.x = 50;
	rect_.y = 50;
}

MainObject :: ~MainObject(){
	free();
}

void MainObject :: handleInput(SDL_Event e, SDL_Renderer* screen, Mix_Chunk* bullet_sound[3]){
	if(e.type == SDL_KEYDOWN){
		switch (e.key.keysym.sym)
		{
		case SDLK_DOWN:
		    if(rect_.y  + 32 > 300) rect_.y = 300;
			else rect_.y += 32;
			break;
		case SDLK_UP:
		    if(rect_.y -32 < 45) rect_.y = 50;
			else rect_.y -= 32;
			break;
		case SDLK_RIGHT:
		    if(rect_.x + 132 > screen_width) rect_.x = screen_width - 132;
			else rect_.x += 32;
			break;
		case SDLK_LEFT:
		    if(rect_.x -32 < 0) rect_.x = 0;
			else rect_.x -= 32;
			break;
		}
    }else if(e.type == SDL_MOUSEBUTTONDOWN){
		if(e.button.button == SDL_BUTTON_LEFT){
			BulletObject* vu = new BulletObject();
			vu->set_x(32);
			vu->loadFromFile("res/laser.png",screen);
			vu->setRect(rect_.x + 50, rect_.y + 20);
            vu->set_buller_dir(BulletObject :: DIR_RIGHT);
			vu->set_is_move(true);
			v_bullet_list.push_back(vu);
			Mix_PlayChannel(-1, bullet_sound[0], 0);
		}else if(e.button.button == SDL_BUTTON_RIGHT){
			BulletObject* vu = new BulletObject();
			vu->set_x(32);
			vu->loadFromFile("res/b13.png",screen);
			vu->setRect(rect_.x + 50, rect_.y + 20);
            vu->set_buller_dir(BulletObject :: DIR_RIGHT_DOWN);
			vu->set_is_move(true);
			v_bullet_list.push_back(vu);
			Mix_PlayChannel(-1, bullet_sound[1], 0);
		}else if(e.button.button == SDL_BUTTON_MIDDLE){
            BulletObject* vu = new BulletObject();
			vu->set_x(32);
			vu->loadFromFile("res/bl12.png",screen);
			vu->setRect(rect_.x + 50, rect_.y + 20);
            vu->set_buller_dir(BulletObject :: DIR_RIGHT_UP);
			vu->set_is_move(true);
			v_bullet_list.push_back(vu);
			Mix_PlayChannel(-1, bullet_sound[2], 0);
        }
	}
}

void MainObject :: handleBullet(SDL_Renderer* des){
	for(unsigned int i = 0; i < v_bullet_list.size(); i++){
		BulletObject* vbullet = v_bullet_list.at(i);
		if(vbullet != NULL){
			if(vbullet->get_is_move() == true){
				vbullet->handlemove(screen_width, screen_height);
				vbullet->render(des, NULL);
			}else{
				v_bullet_list.erase(v_bullet_list.begin() + i);
				if(vbullet != NULL){
					delete vbullet;
					vbullet = NULL;
				}
			}
		}
	}
}