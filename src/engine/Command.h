// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H


namespace engine {
  class MoveCamera;
}

#include "CmdTypeID.h"

namespace engine {

  /// class Command - 
  class Command {
    // Associations
    engine::CmdTypeID cmdType;
    // Attributes
  protected:
    MoveCamera* v;
    // Operations
  public:
    virtual ~Command ();
    virtual CmdTypeID getCmdTypeID () = 0;
    void setMoveCamera (MoveCamera* v);
    MoveCamera* getMoveCamera ();
  };

};

#endif
