#include "baseobject.h"

BaseObject :: BaseObject(){
	rect_.x = 50;
	rect_.y = 50;
	rect_.w = 0;
	rect_.h = 0;
	mTexture = NULL;
}

void BaseObject :: free(){
	if(mTexture != NULL){
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		rect_.x = 0;
		rect_.y = 0;
		// rect_.w = 0;
		// rect_.h = 0;
	}
}

BaseObject :: ~BaseObject(){
	free();
}

bool BaseObject :: loadFromFile(string path, SDL_Renderer* screen){
	SDL_Surface* loadedesurface = IMG_Load(path.c_str());
	SDL_Texture* newTexture = NULL;
	if(loadedesurface == NULL){
		cout << "Khong the load anh\n" << IMG_GetError();
		return false;
	}else{
		SDL_SetColorKey(loadedesurface, SDL_TRUE, SDL_MapRGB(loadedesurface->format, 0x00, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(screen, loadedesurface);
		if(newTexture == NULL){
			cout << "Khong the tao ra texture\n" << SDL_GetError();
			return false;
		}else{
			rect_.w = loadedesurface->w;
			rect_.h = loadedesurface->h;
		}
		SDL_FreeSurface(loadedesurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

void BaseObject :: render(SDL_Renderer* screen, SDL_Rect* clip){
	SDL_Rect render = {rect_.x, rect_.y, rect_.w, rect_.h};
	if(clip != NULL){
		render.w = clip->w;
		render.h = clip->h;
	}
	SDL_RenderCopy(screen, mTexture, clip, &render);
}
