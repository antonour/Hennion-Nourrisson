// Generated by dia2code
#ifndef ENGINE__SELECTFOWL__H
#define ENGINE__SELECTFOWL__H

#include "../state.hpp"

namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class SelectFowl - 
  class SelectFowl : public engine::Action {
    // Attributes
  protected:
    int idx;
    bool TeamChange;
    // Operations
  public:
    SelectFowl (int idx, bool TeamChange);
    void apply (state::State* s, bool notify);
  };

};

#endif