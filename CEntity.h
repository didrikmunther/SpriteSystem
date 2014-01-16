#ifndef CENTITY_H
#define CENTITY_H

#include <SDL.h>
#include "CBody.h"
#include "CSprite.h"
#include <iostream>

class CEntity
{
public:
    CEntity(CSprite* Sprite);
    ~CEntity();

public:
    CBody Body;

    CSprite* Sprite;

public:
    void OnLoop();

    void OnRender(SDL_Surface* Surf_Destination);

};

#endif // CENTITY_H
