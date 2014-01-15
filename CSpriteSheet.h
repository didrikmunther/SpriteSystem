#ifndef CSPRITESHEET_H
#define CSPRITESHEET_H

#include <SDL.h>
#include <string>
#include "CSurface.h"

class CSpriteSheet
{
public:
    static CSpriteSheet* TileSheet;

public:
    CSpriteSheet(std::string Path, int Size);
    ~CSpriteSheet();

public:
    SDL_Surface* Surf_Sheet;

    int Size;

public:
    static void ConstructSheets();

};

#endif // CSPRITESHEET_H
