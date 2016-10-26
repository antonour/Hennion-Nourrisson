// Generated by dia2code
#ifndef RENDER__TILESET__H
#define RENDER__TILESET__H


namespace Render {
  class Tile;
};
namespace state {
  class Element;
}

#include "Tile.h"

namespace Render {

  /// class TileSet - 
  class TileSet {
    // Associations
    // Operations
  public:
    ~TileSet ();
    const char* getImageFile () const;
    const Tile* getCharTile (char c) const;
    const Tile* getElementTile (state::Element* e);
  };

};

#endif
