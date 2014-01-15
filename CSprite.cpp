#include "CSprite.h"

#include <iostream>

CSprite* CSprite::TestSprite = nullptr;

CSprite::CSprite(int x, int y, int w, int h, CSpriteSheet* SpriteSheet)
{
    Offset.x = x;
    Offset.y = y;
    Offset.w = w;
    Offset.h = h;

    this->SpriteSheet = SpriteSheet;
}

CSprite::~CSprite()
{
}

void CSprite::OnRender(int x, int y, SDL_Surface* Surf_Destination)
{
    CSurface::ApplySprite(x, y, this, Surf_Destination); // It crashes here.
}

void CSprite::ConstructSheets()
{
    CSprite::TestSprite = new CSprite(0, 0, 16, 16, CSpriteSheet::TileSheet);
}

SDL_Surface* CSprite::GetSurface()
{
    std::cout << Offset.y << std::endl; // This is where it crashes

    return SpriteSheet->Surf_Sheet; // This is where it crashes
}
