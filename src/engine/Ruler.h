// Generated by dia2code
#ifndef ENGINE__RULER__H
#define ENGINE__RULER__H

#include "../state.hpp"

namespace engine {
  class CommandSet;
  class ActionList;
}

#include "ActionList.h"

namespace engine {

  /// class Ruler - 
  class Ruler {
    // Associations
    // Attributes
  protected:
    const state::State& currentState;
    const CommandSet& commands;
    ActionList& actions;
    // Operations
  public:
    Ruler (ActionList& a, const state::State& s, const CommandSet& c);
    ~Ruler ();
    void collisions ();
    void apply ();
  protected:
    void MoveMyFowl (int idx);
    void MoveMyWeapon (int idx);
    void ZoomInWanted ();
    void ZoomOutWanted ();
    void Shoot ();
    void ChooseMyWeapon (int idx);
  };

};

#endif