// Generated by dia2code
#ifndef ENGINE__SELECTWEAPON__H
#define ENGINE__SELECTWEAPON__H

#include "../state.hpp"

namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class SelectWeapon - 
  class SelectWeapon : public engine::Action {
    // Attributes
  protected:
    int idx;
    int idWeapon;
    // Operations
  public:
    SelectWeapon (int idx, int idWeapon);
    void apply (state::State* s, bool notify);
  };

};

#endif
