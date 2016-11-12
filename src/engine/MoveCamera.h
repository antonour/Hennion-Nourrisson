// Generated by dia2code
#ifndef ENGINE__MOVECAMERA__H
#define ENGINE__MOVECAMERA__H

#include <SFML/Graphics.hpp>
#include "../state.hpp"

namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class MoveCamera - 
  class MoveCamera : public engine::Action {
    // Attributes
  protected:
    sf::View view;
    int dxCenter;
    int dyCenter;
    float dzoom;
    // Operations
  public:
    MoveCamera ();
    ~MoveCamera ();
    void ZoomIn ();
    void ZoomOut ();
    void MoveOnLeft ();
    void MoveOnRight ();
    void MoveOnUp ();
    void MoveOnDown ();
    sf::View getView ();
    void setCenter (int x, int y);
    void apply (state::State* s, bool notify);
  };

};

#endif
