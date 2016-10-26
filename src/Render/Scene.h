// Generated by dia2code
#ifndef RENDER__SCENE__H
#define RENDER__SCENE__H

#include <vector>

namespace Render {
  class Layer;
};
namespace state {
  class State;
  class StateEvent;
  class IObserver;
}

#include "state/IObserver.h"
#include "Layer.h"

namespace Render {

  /// class Scene - 
  class Scene : public state::IObserver {
    // Associations
    // Attributes
  public:
    int Width;
    int Height;
    std::vector<Layer*> layers;
    // Operations
  public:
    Scene ();
    ~Scene ();
    int getWidth () const;
    int getHeight () const;
    int getLayerCount () const;
    void setLayer (int idx, Layer* layer);
    void registerObservers (const state::State* s);
    void unregisterObservers (const state::State* s);
    void stateChanged (state::StateEvent* e);
  };

};

#endif
