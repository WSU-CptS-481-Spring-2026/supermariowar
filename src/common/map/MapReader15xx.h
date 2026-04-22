#pragma once
#include "MapReader.h"

class MapReader1500 : public MapReader {
public:
    virtual bool load(CMap&, BinaryFile&, ReadType);

protected:
    virtual void read_autofilters(CMap&, BinaryFile&); // compat: autofilters disabled
    virtual void read_tiles(CMap&, BinaryFile&); // one-tileset mapdata, separately stored objects
    virtual void read_background(CMap&, BinaryFile&); // background by ID
    virtual void read_music_category(CMap&, BinaryFile&); // compat: music guessed by background
};