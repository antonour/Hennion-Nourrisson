// Generated by dia2code
#ifndef ENGINE__RULER__H
#define ENGINE__RULER__H

#include "../state.hpp"

namespace engine {
  class CommandSet;
  class ActionList;
  class MoveCommand;
  class FireCommand;
}

#include "ActionList.h"

namespace engine {

  /// class Ruler - 
  class Ruler {
    // Associations
    // Attributes
  protected:
    state::State* currentState;
    CommandSet* commands;
    ActionList* actions;
    bool jumped;
    // Operations
  public:
    Ruler (ActionList* a, state::State* s, CommandSet* c);
    ~Ruler ();
    void apply ();
    void resetJump ();
  protected:
    bool isMovable (state::State* s, MoveCommand* m);
    bool isFalling (state::State* s, MoveCommand* m);
    bool canJumpOver (state::State* s, MoveCommand* m);
    bool canHit (state::State* s, FireCommand* fire);
    int canKill (state::State* s, FireCommand* fire);
  };

};

#endif
