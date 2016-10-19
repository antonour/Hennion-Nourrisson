// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <map>

namespace Render {
  class Surface;
  class Tile;
  class TileSet;
  class Animation;
};
namespace state {
  class StateEvent;
  class IObserver;
}

#include "state/IObserver.h"
#include "Animation.h"
#include "TileSet.h"
#include "Surface.h"

namespace Render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  public:
    Surface* surface;
  private:
    std::map<int,Animation*> animations;
  protected:
    const Tile* tileset;
    // Operations
  public:
    Layer ();
    virtual ~Layer ();
    const TileSet* getTileSet ();
    void setTileSet (const TileSet* tileset);
    void setSurface (Surface* surface);
    void setAnimation (int i, Animation* a);
    void printText (int x, int y, const char* msg, int spriteIdx, int w, int h);
    void stateChanged (const state::StateEvent& e);
  };

};

#endif
