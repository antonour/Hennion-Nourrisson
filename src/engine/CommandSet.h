// Generated by dia2code
#ifndef ENGINE__COMMANDSET__H
#define ENGINE__COMMANDSET__H

#include <map>

namespace engine {
  class Command;
  class CommandSet;
}

#include "Command.h"

namespace engine {

  /// class CommandSet - 
  class CommandSet {
    // Associations
    // Attributes
  protected:
    std::map<int,Command*> commands;
    // Operations
  public:
    ~CommandSet ();
    int  size () const;
    Command* get (int category);
    void set (Command* cmd);
    void take (CommandSet& commands, bool replace);
  };

};

#endif
