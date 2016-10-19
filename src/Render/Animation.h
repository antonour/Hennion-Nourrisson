// Generated by dia2code
#ifndef RENDER__ANIMATION__H
#define RENDER__ANIMATION__H


namespace Render {
  class Tile;
}

#include "state/Direction.h"

namespace Render {

  /// class Animation - 
  class Animation {
    // Attributes
  public:
    int i;
  protected:
    int x;
    int y;
    const Tile* tile;
    state::Direction direction;
    float speed;
    // Operations
  public:
    Animation (int i, int x, int y, const Tile* a);
    void setDirection (state::Direction d);
    void setSpeed (float speed);
  };

};

#endif
