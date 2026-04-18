#ifndef SMW_MAP_LOADER_H
#define SMW_MAP_LOADER_H

#include "FileIO.h"

#include <vector>

class CMap;
class MovingPlatformPath;
struct TilesetTile;
struct Version;
enum ReadType: unsigned char;
enum class TileType : unsigned char;

class MapReader {
public:
    virtual ~MapReader() = default;

    virtual bool load(CMap&, BinaryFile&, ReadType) = 0;

    static MapReader* getLoaderByVersion(const Version& mapversion);
};

#endif // SMW_MAP_LOADER_H
