#pragma once
#include "MapReader17xx.h"

class MapReader1800 : public MapReader1702 {
public:
    MapReader1800();
    virtual bool load(CMap&, BinaryFile&, ReadType);

protected:
    virtual void read_autofilters(CMap& map, BinaryFile& mapfile); // 13 autofilters
    virtual void read_tileset(BinaryFile&); // custom tileset support
    virtual void read_tiles(CMap&, BinaryFile&); // multi-tileset mapdata
    virtual void read_switches(CMap&, BinaryFile&); // switches stored as-is
    virtual void read_items(CMap&, BinaryFile&); // map item support
    virtual void read_hazards(CMap&, BinaryFile&); // map hazard support
    virtual void read_warp_locations(CMap&, BinaryFile&);
    virtual void read_switchable_blocks(CMap&, BinaryFile&);
    virtual bool read_spawn_areas(CMap&, BinaryFile&);
    virtual void read_extra_tiledata(CMap&, BinaryFile&);
    virtual void read_gamemode_settings(CMap&, BinaryFile&);
    virtual void read_platforms(CMap&, BinaryFile&, bool preview);
    virtual std::pair<std::vector<TilesetTile>, std::vector<TileType>> read_platform_tiles(CMap&, BinaryFile&, short w, short h);

private:
    short iMaxTilesetID;
    short* translationid;
    short* tilesetwidths;
    short* tilesetheights;
};

class MapReader1801 : public MapReader1800 {
public:
    MapReader1801();
};

class MapReader1802 : public MapReader1801 {
public:
    MapReader1802();

protected:
    virtual void read_eyecandy(CMap&, BinaryFile&); // 3-layer eyecandy support
};