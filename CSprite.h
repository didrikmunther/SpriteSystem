#ifndef CSPRITE_H
#define CSPRITE_H

#include <SDL.h>
#include "CSpriteSheet.h"
#include "CSurface.h"

class CSpriteSheet;

class CSprite
{
public:
    static CSprite* TestSprite;

    CSprite(int x, int y, int w, int h, CSpriteSheet* SpriteSheet);
    ~CSprite();

public:
    SDL_Rect Offset;

    CSpriteSheet* SpriteSheet;

public:
    void OnRender(int x, int y, SDL_Surface* Surf_Destination);

public:
    static void ConstructSheets();

    SDL_Surface* GetSurface();

};

#endif // CSPRITE_H
