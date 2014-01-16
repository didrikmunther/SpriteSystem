#include "CSurface.h"

void CSurface::RenderRect(int x, int y, int w, int h, SDL_Surface* Surface_Destination, int r, int g, int b)
{
    SDL_Rect Rect;

    Rect.x = x;
    Rect.y = y;
    Rect.w = w;
    Rect.h = h;

    SDL_FillRect(Surface_Destination, &Rect, SDL_MapRGB(Surface_Destination->format, r, g, b));
}

void CSurface::RenderRect(int x, int y, int w, int h, SDL_Surface* Surface_Destination, Uint32 Color)
{
    SDL_Rect Rect;

    Rect.x = x;
    Rect.y = y;
    Rect.w = w;
    Rect.h = h;

    SDL_FillRect(Surface_Destination, &Rect, Color);
}

void CSurface::RenderRect(SDL_Rect* Rect, SDL_Surface* Surface_Destination, int r, int g, int b)
{
    SDL_FillRect(Surface_Destination, Rect, SDL_MapRGB(Surface_Destination->format, r, g, b));
}

void CSurface::RenderRect(SDL_Rect* Rect, SDL_Surface* Surface_Destination, Uint32 Color)
{
    SDL_FillRect(Surface_Destination, Rect, Color);
}

SDL_Surface* CSurface::LoadSurface(std::string Path)
{
    SDL_Surface* LoadedSurface = NULL;
    SDL_Surface* OptimizedSurface = NULL;

    LoadedSurface = IMG_Load(Path.c_str());

    if(LoadedSurface != NULL)
    {
        OptimizedSurface = SDL_DisplayFormatAlpha(LoadedSurface);

        SDL_FreeSurface(LoadedSurface);
    }

    return OptimizedSurface;

}

void CSurface::ApplySurface(int x, int y, SDL_Surface* Source, SDL_Surface* Destination)
{
    SDL_Rect Offset;

    Offset.x = x;
    Offset.y = y;

    SDL_BlitSurface(Source, nullptr, Destination, &Offset);
}

void CSurface::ApplySprite(int x, int y, CSprite* Sprite, SDL_Surface* Destination)
{
    SDL_Rect Offset;

    Offset.x = x;
    Offset.y = y;

    SDL_BlitSurface(Sprite->GetSurface(), &Sprite->Offset, Destination, &Offset); // It crashes here

}
