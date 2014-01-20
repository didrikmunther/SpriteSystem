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

        // Temporary delay
        // Limits FPS to 200
        SDL_Delay(5);
    }

    std::cout << "Leaving game loop\n";

    std::cout << "Cleaning up...\n";

    OnCleanup();

    std::cout << "Done!\n";

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

    // Now that SDL_Init() has been called we can now load all the SpriteSheets.
    std::cout << "Loading graphics...\n";

    for(auto it = ResourceManager.SpriteSheetMap.begin(); it != ResourceManager.SpriteSheetMap.end(); it++)
    {
        if((it->second->Surf_Sheet = CSurface::LoadSurface(it->second->Path)) == NULL)
        {
            std::cout << "error: " << it->second->Path << " is not present.\n";
            return -2;
        }
    }

    //==

    MyEntity = std::shared_ptr<CEntity>(new CEntity(ResourceManager.SpriteMap.find("Apple")->second));

    EntityList.push_back(MyEntity);
    EntityList.push_back(std::make_shared<CEntity>(ResourceManager.SpriteMap.find("Bucket")->second));

    //==

    return 0;
}

void CApp::OnLoop()
{
    // Temporary
    if(MouseDown)
    {
        MyEntity->Body.X = MouseX - 8;
        MyEntity->Body.Y = MouseY - 8;
    }

    // Loop all Entities
    for (auto it = EntityList.begin();
        it != EntityList.end();
        it++)
    {
        (*it)->OnLoop();
    }
}

void CApp::OnRender()
{
    // Render background
    CSurface::RenderRect(&BackgroundRect, Surface_Display, BackgroundColor);

    // Render all Entities
    for (auto it = EntityList.begin();
        it != EntityList.end();
        it++)
    {
        (*it)->OnRender(Surface_Display);
    }

    //==

    SDL_Flip(Surface_Display);
}

void CApp::OnCleanup()
{
    EntityList.clear();

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
