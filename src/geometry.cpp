#include "geometry.h"

void Geometry :: Render_HCN(const GeometryFormat& g_size, const ColorData& g_color, SDL_Renderer* screen){
    SDL_Rect fillRect = {g_size.left, g_size.top, g_size.width, g_size.height};
    SDL_SetRenderDrawColor(screen, g_color.red_, g_color.green_, g_color.blue_, 0xFF);
    SDL_RenderFillRect(screen, &fillRect);
}

void Geometry :: Render_Outline(const GeometryFormat& g_size, const ColorData& g_color, SDL_Renderer* screen){
    SDL_Rect outRect = {g_size.left, g_size.top, g_size.width, g_size.height};
    SDL_SetRenderDrawColor(screen, g_color.red_, g_color.green_, g_color.blue_, 0xFF);
    SDL_RenderDrawRect(screen, &outRect);
}