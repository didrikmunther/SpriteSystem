#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <sstream>
#include "CSurface.h"

#include "CEntity.h"
#include "CSprite.h"

#include <iostream>

class CApp
{
private:
    SDL_Surface* Surface_Display;
    SDL_Event Event;

    bool Running;

    const int WIDTH;
    const int HEIGHT;
    const int BPP;

    bool MouseDown;
    int MouseX;
    int MouseY;

    std::stringstream Title;
    std::string Intro;

    //==

    float LastTime;
    float Timer;
    const float NS;
    float Delta;
    int Frames;
    int Updates;

    //==

    Uint32 BackgroundColor;
    SDL_Rect BackgroundRect;

    CEntity* ATile = new CEntity(CSprite::TestSprite); // This is the entity I want to render

public:
    CApp();

    ~CApp();

    int OnExecute();

private:
    int OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();

    void OnCleanup();

};

#endif // CAPP_H
