#ifndef CRESOURCEMANAGER_H
#define CRESOURCEMANAGER_H

#include <map>
#include <memory>
#include <string>
#include "CSprite.h"
#include "CSpriteSheet.h"

class CResourceManager
{
public:
    CResourceManager();
    ~CResourceManager();

    std::map<std::string, std::shared_ptr<CSprite>> SpriteMap;
    std::map<std::string, std::shared_ptr<CSpriteSheet>> SpriteSheetMap;
};

#endif // CRESOURCEMANAGER_H
