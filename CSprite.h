#ifndef CSPRITE_H
#define CSPRITE_H

#include <SDL.h>
#include "CSpriteSheet.h"
#include "CSurface.h"
#include <vector>
#include <memory>

class CSpriteSheet;

class CSprite
{
public:
    CSprite(int x, int y, int w, int h, std::shared_ptr<CSpriteSheet> SpriteSheet);
    ~CSprite();

    SDL_Rect Offset;

    std::shared_ptr<CSpriteSheet> SpriteSheet;

    void OnRender(int x, int y, SDL_Surface* Surf_Destination);

    SDL_Surface* GetSurface();

};

#endif // CSPRITE_H
