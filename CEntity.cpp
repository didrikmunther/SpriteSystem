#include "CEntity.h"

CEntity::CEntity(CSprite* Sprite) :
Sprite(Sprite)
{
}

CEntity::~CEntity()
{
    std::cout << "talking CEntity\n";
}

void CEntity::OnRender(SDL_Surface* Surf_Destination)
{
    std::cout << "From CEntity::OnRender()\n";

    Sprite->OnRender(Body.X, Body.Y, Surf_Destination);
}

