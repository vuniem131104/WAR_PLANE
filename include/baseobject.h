#ifndef baseobject_h
#define baseobject_h
#include "common.h"
class BaseObject{
	public:
	BaseObject();
	~BaseObject();
	void render(SDL_Renderer* screen, SDL_Rect* clip = NULL);
	bool loadFromFile(string path, SDL_Renderer* screen);
	void free();
	void setRect(int x, int y){
		rect_.x = x;
		rect_.y = y;
	}
	SDL_Rect getRect(){
		return rect_;
	}
	void setW(int ww){
		rect_.w = ww;
	}
	void setH(int hh){
		rect_.h = hh;
	}
	int getwidth(){
		return rect_.w;
	}
	int getheight(){
		return rect_.h;
	}
	int getX(){
		return rect_.x;
	}
	int getY(){
		return rect_.y;
	}
	protected:
	SDL_Rect rect_;
	SDL_Texture* mTexture;
};
#endif 