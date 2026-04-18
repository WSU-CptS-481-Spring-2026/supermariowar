#pragma once
#include "MapReader16xx.h"

class MapReader1700 : public MapReader1600 /* ignore 1.6 patches */ {
public:
    MapReader1700();
    virtual bool load(CMap&, BinaryFile&, ReadType);

protected:
    virtual void read_tiles(CMap&, BinaryFile&); // one-tileset mapdata
    virtual void set_preview_switches(CMap&, BinaryFile&); // compat: switches disabled
    virtual void read_warp_locations(CMap&, BinaryFile&);
    virtual void read_switches(CMap&, BinaryFile&); // switches stored inverted
    virtual bool read_spawn_areas(CMap&, BinaryFile&);

    virtual void read_platforms(CMap&, BinaryFile&, bool preview);
    virtual std::pair<std::vector<TilesetTile>, std::vector<TileType>> read_platform_tiles(CMap&, BinaryFile&, short w, short h);
    MovingPlatformPath* read_platform_path_details(BinaryFile&, short type, bool preview);

    unsigned char patch_version;
};

class MapReader1701 : public MapReader1700 {
public:
    MapReader1701();

protected:
    virtual void read_background(CMap&, BinaryFile&); // background by underscore-conversion
    virtual void read_music_category(CMap&, BinaryFile&); // music by category ID
};

class MapReader1702 : public MapReader1701 {
public:
    MapReader1702();

protected:
    virtual void read_autofilters(CMap& map, BinaryFile& mapfile); // 9 autofilter support
    virtual void read_background(CMap&, BinaryFile&); // background as string
};