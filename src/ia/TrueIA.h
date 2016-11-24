// Generated by dia2code
#ifndef IA__TRUEIA__H
#define IA__TRUEIA__H

#include "../state.hpp"
#include "../engine.hpp"

namespace ia {
  class AI;
}

#include "AI.h"

namespace ia {

  /// class TrueIA - 
  class TrueIA : public ia::AI {
    // Attributes
  protected:
    state::State* futureState;
    int ite1;
    int ite2;
    int ite3;
    int min;
    // Operations
  public:
    TrueIA (state::State* currentState);
    int findNearestWay ();
    engine::Command* run (state::State* s);
    int findHole (int X, int Y, int& DX);
    void findLanding (int X, int Y, int& DY);
    int getMin ();
    void setIterateurs (int i, int j, int k);
  };

};

#endif
