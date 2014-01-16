#include "CEntity.h"

CEntity::CEntity(CSprite* Sprite) :
Sprite(Sprite)
{
}

CEntity::~CEntity()
{
    std::cout << "Entity dtor\n";
}

void CEntity::OnRender(SDL_Surface* Surf_Destination)
{

    Sprite->OnRender(Body.X, Body.Y, Surf_Destination);
}

void CEntity::OnLoop()
{

//    time += 1.0f/60.0f;
//
//    if((Body.X >= 0) && (Body.X + 16 <= 640))
//        Body.X += time * Body.VelX;
//
//    if(!((Body.X >= 0) && (Body.X + 16 <= 640)))
//        Body.X = 640 - 16;
//
//    if((Body.Y >= 0) && (Body.Y + 16 <= 480))
//        Body.Y += time * Body.VelY + time * time * 20 / 2;
//
//    if(!((Body.Y >= 0) && (Body.Y + 16 <= 480)))
//        Body.Y = 480 - 16;

}
