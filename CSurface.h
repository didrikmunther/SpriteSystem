#ifndef CSurface_H
#define CSurface_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "CSprite.h"
#include "CSpriteSheet.h"

#include <iostream>

class CSprite;

namespace CSurface
{
    // Rectangle Methods
    void RenderRect(int x, int y, int w, int h, SDL_Surface* Surface_Destination, int r, int g, int b);

    void RenderRect(int x, int y, int w, int h, SDL_Surface* Surface_Destination, Uint32 Color);

    void RenderRect(SDL_Rect* Rect, SDL_Surface* Surface_Destination, int r, int g, int b);

    void RenderRect(SDL_Rect* Rect, SDL_Surface* Surface_Destination, Uint32 Color);

    // Surface Methods
    SDL_Surface* LoadSurface(std::string Path);

    void ApplySurface(int x, int y, SDL_Surface* Source, SDL_Surface* Destination);

    void ApplySprite(int x, int y, CSprite* Sprite, SDL_Surface* Destination);

}

#endif // CSurface_H
