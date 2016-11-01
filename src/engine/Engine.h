// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include "../state.hpp"
#include <mutex>
#include <stdint.h>

namespace engine {
  class CommandSet;
  class Command;
  class Ruler;
}

#include "EngineMode.h"
#include "Ruler.h"
#include "CommandSet.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    engine::EngineMode mode;
    // Attributes
  protected:
    state::ElementFactory factory;
    state::State currentState;
    mutable std::mutex commands_mutex;
    CommandSet* currentCommands;
    mutable std::mutex update_mutex;
    int64_t lastUpdateTime;
    // Operations
  public:
    Engine ();
    ~Engine ();
    EngineMode getMode () const;
    const state::State& getState () const;
    void addCommand (Command* cmd);
    void takeCommands (CommandSet& commands);
    std::mutex& getUpdateMutex () const;
    bool update (int64_t time, int64_t* next_time = NULL);
  protected:
    void setMode (EngineMode mode);
    void loadlevel (const char* file_name);
  };

};

#endif
