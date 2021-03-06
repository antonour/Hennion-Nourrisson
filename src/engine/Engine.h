// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include "../state.hpp"
#include <stdint.h>
#include <mutex>

namespace engine {
  class CommandSet;
  class Ruler;
  class Command;
}

#include "Ruler.h"
#include "CommandSet.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  protected:
    state::ElementFactory factory;
    state::State* currentState;
    CommandSet* currentCommands;
    CommandSet* waiting_commands;
    int64_t lastUpdateTime;
    Ruler* rules;
    mutable std::mutex commands_mutex;
    mutable std::mutex apply_mutex;
    // Operations
  public:
    void loadlevel ();
    Engine ();
    ~Engine ();
    state::State* getState ();
    void setState (state::State* s);
    void addCommand (Command* cmd);
    void takeCommands (CommandSet* commands, CommandSet* commands1);
    void setRuler (Ruler* r);
    bool update (int64_t time);
    void runEngine ();
  };

};

#endif
