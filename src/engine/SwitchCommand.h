// Generated by dia2code
#ifndef ENGINE__SWITCHCOMMAND__H
#define ENGINE__SWITCHCOMMAND__H


namespace engine {
  class Command;
}

#include "CmdTypeID.h"
#include "Command.h"

namespace engine {

  /// class SwitchCommand - 
  class SwitchCommand : public engine::Command {
    // Attributes
  protected:
    int idx;
    // Operations
  public:
    CmdTypeID getCmdTypeID ();
    void setIDX (int idx);
    int getIDX ();
  };

};

#endif
