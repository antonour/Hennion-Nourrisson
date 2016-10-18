// Generated by dia2code
#ifndef RENDER__TILE__H
#define RENDER__TILE__H


namespace Render {

  /// class Tile - 
  class Tile {
    // Operations
  public:
    virtual int getWidth () const = 0;
    virtual int getHeight () const = 0;
    virtual bool isMovable () const = 0;
  };

};

#endif
