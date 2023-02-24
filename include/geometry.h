#ifndef geometry_h
#define geometry_h
#include "common.h"

struct GeometryFormat{
    GeometryFormat(int l, int t, int w, int h){
        left = l;
        top = t;
        width = w;
        height = h;
    }
    int left;
    int top;
    int width;
    int height;
};

struct ColorData{
    ColorData(Uint8 r, Uint8 g, Uint8 b){
        red_ = r;
        green_ = g;
        blue_ = b;
    }
    Uint8 red_;
    Uint8 green_;
    Uint8 blue_;
};

class Geometry{
    public:
    static void Render_HCN(const GeometryFormat& g_size, const ColorData& g_color, SDL_Renderer* screen);
    static void Render_Outline(const GeometryFormat& g_size, const ColorData& g_color, SDL_Renderer* screen);
};

#endif // !