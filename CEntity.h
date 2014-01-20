#ifndef CENTITY_H
#define CENTITY_H

#include <SDL.h>
#include <vector>
#include "CBody.h"
#include "CSprite.h"
#include <iostream>
#include <memory>

class CEntity
{
public:
    CEntity(std::shared_ptr<CSprite> Sprite);
    ~CEntity();

    CBody Body;

    std::shared_ptr<CSprite> Sprite;

    void OnLoop();

    void OnRender(SDL_Surface* Surf_Destination);

};

#endif // CENTITY_H
