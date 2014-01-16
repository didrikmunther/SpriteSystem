#ifndef CSPRITESHEET_H
#define CSPRITESHEET_H

#include <SDL.h>
#include <string>
#include "CSurface.h"
#include <vector>

class CSpriteSheet
{
public:
    static std::vector<CSpriteSheet*> SpriteSheetList;

    static CSpriteSheet* MinecraftSheet;

public:
    CSpriteSheet(std::string Path);
    ~CSpriteSheet();

public:
    SDL_Surface* Surf_Sheet;

    std::string Path;

public:
    static int ConstructSheets();

};

#endif // CSPRITESHEET_H
