#include "CSprite.h"

#include <iostream>

std::vector<CSprite*> CSprite::SpriteList;

CSprite* CSprite::MinecraftSprite = new CSprite(10 * 16, 0 * 16, 16, 16, CSpriteSheet::MinecraftSheet);

CSprite::CSprite(int x, int y, int w, int h, CSpriteSheet* SpriteSheet) :
Offset{x, y, w, h}, SpriteSheet(SpriteSheet)
{
    CSprite::SpriteList.push_back(this);
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
