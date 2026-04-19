#pragma once

#include "FileList.h"
#include "GameMode.h"
#include "GameValues.h"
#include "gfx.h"
#include "map.h"
#include "MapList.h"
#include "path.h"
#include "ResourceManager.h"
#include "TilesetManager.h"

#include <cstdio>
#include <algorithm>
#include <array>

// main game directory, read from command line argument
#ifdef __ANDROID__
inline std::string RootDataDirectory = GetHomeDirectory() + "data";
#else
inline std::string RootDataDirectory = GetRootDirectory() + "data";
#endif

inline CGameMode			*gamemodes[GAMEMODE_LAST];

inline CResourceManager *rm;
inline CGameValues game_values;

inline FiltersList *filterslist;  //Filters list must be initiallized before maps list because it is used in maplist constructor
inline MapList *maplist;
inline SkinList *skinlist;
inline AnnouncerList *announcerlist;
inline MusicList *musiclist;
inline WorldMusicList *worldmusiclist;
inline GraphicsList *menugraphicspacklist;
inline GraphicsList *worldgraphicspacklist;
inline GraphicsList *gamegraphicspacklist;
inline SoundsList *soundpacklist;
inline TourList *tourlist;
inline WorldList *worldlist;

inline CMap      *g_map;
inline CTilesetManager *g_tilesetmanager;

//Joystick-Init
inline SDL_Joystick **joysticks = NULL;
inline short joystickcount = 0;