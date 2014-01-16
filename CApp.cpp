#include "CApp.h"

CApp::CApp() :
Running(true), Surface_Display(nullptr),
WIDTH(640), HEIGHT(480), BPP(32),
LastTime(SDL_GetTicks()), Timer(SDL_GetTicks()),
NS(1000.0f/60.0f), Delta(0), Frames(0), Updates(0),
Intro("Physics"),
BackgroundRect{0, 0, WIDTH, HEIGHT},
MouseDown(false), MouseX(0), MouseY(0)
{
//    float LastTime;
//    float Timer;
//    const float NS;
//    float Delta;
//    int Frames;
//    int Updates;
}

int CApp::OnExecute()
{
    switch(OnInit())
    {
    case -1: // SDL_Init() failed.
        std::cout << "SDL_Init() failed.\n";
        return 1;
        break;

    case -2: // A sprite sheet is not present
        OnCleanup();
        return 1;
        break;
    }

    std::cout << "Entering game loop\n";

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        float Now = SDL_GetTicks();
        Delta += (Now - LastTime) / NS;
        LastTime = Now;

        while(Delta >= 1)
        {
            OnLoop();

            Updates++;
            Delta--;
        }

        OnRender();

        Frames++;

        if(SDL_GetTicks() - Timer > 1000)
        {
            Timer += 1000;
            Title.str("");
            Title << Intro << " | " << Updates << " ups, " << Frames << " fps";
            SDL_WM_SetCaption(Title.str().c_str(), nullptr);
            Updates = 0;
            Frames = 0;
        }
    }

    std::cout << "Leaving game loop\n";

    OnCleanup();

    return 0;
}

CApp::~CApp()
{
}

int CApp::OnInit()
{
    std::cout << "CApp::OnInit()\n";

    if((SDL_Init(SDL_INIT_EVERYTHING)) == -1) return -1;

    Surface_Display = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);

    BackgroundColor = SDL_MapRGB(Surface_Display->format, 0xFF, 0xFF, 0xFF);

    //==

    std::cout << "Loading graphics...\n";

    if(CSpriteSheet::ConstructSheets() == -1) return -2;

    //==

    return 0;
}

void CApp::OnLoop()
{
    // Temporary
    if(MouseDown)
    {
        ATile->Body.X = MouseX;
        ATile->Body.Y = MouseY;
    }

    ATile->OnLoop();
}

void CApp::OnRender()
{
    CSurface::RenderRect(&BackgroundRect, Surface_Display, BackgroundColor);

    ATile->OnRender(Surface_Display);

    //==

    SDL_Flip(Surface_Display);
}

void CApp::OnCleanup()
{
    for (std::vector<CSprite*>::iterator it = CSprite::SpriteList.begin();
        it != CSprite::SpriteList.end();
        it++)
    {
        delete *(it);
    }
    CSprite::SpriteList.clear();

    for (std::vector<CSpriteSheet*>::iterator it = CSpriteSheet::SpriteSheetList.begin();
        it != CSpriteSheet::SpriteSheetList.end();
        it++)
    {
        delete *(it);
    }
    CSpriteSheet::SpriteSheetList.clear();

    delete ATile;

    SDL_Quit();
}

void CApp::OnEvent(SDL_Event* Event)
{
    switch(Event->type)
    {
    case SDL_MOUSEMOTION:
        SDL_GetMouseState(&MouseX, &MouseY);
        break;

    case SDL_MOUSEBUTTONDOWN:
        MouseDown = true;
        break;

    case SDL_MOUSEBUTTONUP:
        MouseDown = false;
        break;

    case SDL_KEYDOWN:
        switch(Event->key.keysym.sym)
        {
            default:;
        }
        break;

    case SDL_KEYUP:
        break;
    }

    if(Event->type == SDL_QUIT || Event->key.keysym.sym == SDLK_ESCAPE) Running = false;
}
