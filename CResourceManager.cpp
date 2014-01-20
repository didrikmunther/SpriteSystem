#include "CResourceManager.h"

CResourceManager::CResourceManager()
{
    SpriteSheetMap["Items"] = std::make_shared<CSpriteSheet>(CSpriteSheet("./gfx/minecraft.png"));

    //==

    SpriteMap["Apple"] = std::make_shared<CSprite>(CSprite(10 * 16, 0 * 16, 16, 16, SpriteSheetMap.find("Items")->second));
    SpriteMap["Bucket"] = std::make_shared<CSprite>(CSprite(10 * 16, 4 * 16, 16, 16, SpriteSheetMap.find("Items")->second));
}

CResourceManager::~CResourceManager()
{
    SpriteSheetMap.clear();
    SpriteMap.clear();
}
