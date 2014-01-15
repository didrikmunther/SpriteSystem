#include "CSpriteSheet.h"

#include <iostream>

CSpriteSheet* CSpriteSheet::TileSheet = nullptr;

CSpriteSheet::CSpriteSheet(std::string Path, int Size) :
Surf_Sheet(CSurface::LoadSurface(Path)), Size(Size)
{
}

CSpriteSheet::~CSpriteSheet()
{
    SDL_FreeSurface(Surf_Sheet);
    std::cout << "CSpriteSheet dtor\n";
}

void CSpriteSheet::ConstructSheets()
{
    CSpriteSheet::TileSheet = new CSpriteSheet("blocksheet.bmp", 256);
}
