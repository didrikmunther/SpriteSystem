#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <vector>
#include <map>
#include <sstream>
#include "CSurface.h"
#include "CEntity.h"
#include "CResourceManager.h"
#include <iostream>

class CApp
{
private:
    SDL_Surface* Surface_Display;
    SDL_Event Event;

    bool Running;

    //==

    CResourceManager ResourceManager;

    std::shared_ptr<CEntity> MyEntity;

    std::vector<std::shared_ptr<CEntity>> EntityList;

    //==

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
