#include "CSpriteSheet.h"

#include <iostream>

std::vector<CSpriteSheet*> CSpriteSheet::SpriteSheetList;

CSpriteSheet* CSpriteSheet::MinecraftSheet = new CSpriteSheet("./gfx/minecraft.png");

CSpriteSheet::CSpriteSheet(std::string Path) :
Surf_Sheet(nullptr), Path(Path)
{
    CSpriteSheet::SpriteSheetList.push_back(this);
}

CSpriteSheet::~CSpriteSheet()
{
    SDL_FreeSurface(Surf_Sheet);
    std::cout << "CSpriteSheet dtor\n";
}

// STATIC FUNCTION
// Fills Surf_Sheet on all the static spritesheets
int CSpriteSheet::ConstructSheets()
{
    for (std::vector<CSpriteSheet*>::iterator it = CSpriteSheet::SpriteSheetList.begin();
        it != CSpriteSheet::SpriteSheetList.end();
        it++)
    {
        // Incase loading goes wrong. (in that case the image is probably not there)
        if(((*it)->Surf_Sheet = CSurface::LoadSurface((*it)->Path)) == NULL)
        {
            std::cout << "error: " << (*it)->Path << " is not present.\n";
            return -1;
        }
    }

    return 0;
}
