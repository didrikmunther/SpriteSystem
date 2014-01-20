#ifndef CSPRITESHEET_H
#define CSPRITESHEET_H

#include <SDL.h>
#include <string>
#include "CSurface.h"
#include <vector>

class CSpriteSheet
{
public:
    CSpriteSheet(std::string Path);
    ~CSpriteSheet();

    SDL_Surface* Surf_Sheet;

    std::string Path;

};

#endif // CSPRITESHEET_H
