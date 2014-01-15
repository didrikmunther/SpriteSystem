#include "CApp.h"

CApp::CApp() :
Running(true), Surface_Display(nullptr),
WIDTH(360), HEIGHT(360), BPP(32),
LastTime(SDL_GetTicks()), Timer(SDL_GetTicks()),
NS(1000.0f/60.0f), Delta(0), Frames(0), Updates(0),
Intro("Physics"),
BackgroundRect{0, 0, WIDTH, HEIGHT}
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
    if(OnInit() == -1) return 1;

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        float Now = SDL_GetTicks();
        Delta += (Now - LastTime) / NS;
        LastTime = Now;

//        while(Delta >= 1)
//        {
//            OnLoop();
//
//            Updates++;
//            Delta--;
//        }

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

    OnCleanup();

    return 0;
}

CApp::~CApp()
{
}

int CApp::OnInit()
{
    if((SDL_Init(SDL_INIT_EVERYTHING)) == -1) return -1;

    Surface_Display = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);

    BackgroundColor = SDL_MapRGB(Surface_Display->format, 0, 0xFF, 0xFF);

    //==

    CSpriteSheet::ConstructSheets();
    CSprite::ConstructSheets();

    std::cout << CSpriteSheet::TileSheet->Surf_Sheet << std::endl;

    //==

    return 0;
}

void CApp::OnLoop()
{
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
        break;

    case SDL_KEYUP:
        break;
    }

    if(Event->type == SDL_QUIT || Event->key.keysym.sym == SDLK_ESCAPE) Running = false;
}
