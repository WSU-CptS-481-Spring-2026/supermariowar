#pragma once
#include "MapReader15xx.h"

class MapReader1600 : public MapReader1500 {
public:
    MapReader1600();
    virtual bool load(CMap&, BinaryFile&, ReadType);

protected:
    virtual void read_tiles(CMap&, BinaryFile&); // tiles also contain block and warp data
    virtual void read_eyecandy(CMap&, BinaryFile&); // simple eyecandy support
    virtual bool read_spawn_areas(CMap&, BinaryFile&);
    virtual void read_warp_exits(CMap&, BinaryFile&);
    virtual bool read_draw_areas(CMap&, BinaryFile&);

private:
    bool parse_nospawn;
    bool fix_spawnareas;

    friend class MapReader160A;
    friend class MapReader1610;
};

class MapReader160A : public MapReader1600 {
public:
    MapReader160A();
};

class MapReader1610 : public MapReader160A {
public:
    MapReader1610();
    virtual bool load(CMap&, BinaryFile&, ReadType);
};