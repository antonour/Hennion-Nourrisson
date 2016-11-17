// Generated by dia2code
#ifndef ENGINE__FOWLJUMP__H
#define ENGINE__FOWLJUMP__H

#include "../state.hpp"

namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class FowlJump - 
  class FowlJump : public engine::Action {
    // Attributes
  protected:
    int idx;
    // Operations
  public:
    FowlJump (int idx);
    ~FowlJump ();
    void apply (state::State* s, bool notify);
  };

};

#endif
