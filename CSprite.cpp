#include "CSprite.h"
#include <iostream>

CSprite::CSprite(int x, int y, int w, int h, std::shared_ptr<CSpriteSheet> SpriteSheet) :
Offset{x, y, w, h}, SpriteSheet(SpriteSheet)
{
}

CSprite::~CSprite()
{
    std::cout << "CSprite dtor\n";
}

void CSprite::OnRender(int x, int y, SDL_Surface* Surf_Destination)
{
    CSurface::ApplySprite(x, y, this, Surf_Destination);
}

SDL_Surface* CSprite::GetSurface()
{
    return SpriteSheet->Surf_Sheet;
}
