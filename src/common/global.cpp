#include "global.h"

//Koopa Bros Weapons
//Mushrooms Only
//Super Mario Bros (All mushrooms ((poison was in lost levels, that counts as SMB1)), fireflower, star, and maybe the shells)
//Super Mario Bros 2 (All mushrooms but poison, star, clock, pow, green/red shell, bombs)
//One I'd like to see is SMWorld (esc{sp}) only stuff...
//0,10,0,1,0,10,6,0,0,0,2,0,8,4,2,4,0,10,0,5,2,0,0


//Conversion from backgrounds to music categories created by NMcCoy
const char * g_szMusicCategoryNames[MAXMUSICCATEGORY] = {"Land", "Underground", "Underwater", "Castle", "Platforms", "Ghost", "Bonus", "Battle", "Desert", "Clouds", "Snow"};


void LoadCurrentMapBackground()
{
    std::string path = concat("gfx/packs/backgrounds/", g_map->szBackgroundFile);
    path = convertPath(path, gamegraphicspacklist->currentPath());

    //if the background file doesn't exist, use the classic background
    if (!FileExists(path))
        path = convertPath("gfx/packs/backgrounds/Land_Classic.png", gamegraphicspacklist->currentPath());

    gfx_loadimagenocolorkey(&rm->spr_background, path);
}
