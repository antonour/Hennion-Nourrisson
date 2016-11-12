// Generated by dia2code
#ifndef ENGINE__KILLCOMMAND__H
#define ENGINE__KILLCOMMAND__H


namespace engine {
  class Command;
}

#include "CmdTypeID.h"
#include "Command.h"

namespace engine {

  /// class KillCommand - 
  class KillCommand : public engine::Command {
    // Attributes
  protected:
    int idx;
    // Operations
  public:
    KillCommand (int idx);
    CmdTypeID getCmdTypeID ();
    void setIDX (int idx);
    int getIDX ();
  };

};

#endif