// Generated by dia2code
#ifndef STATE__FOWLCREATOR__H
#define STATE__FOWLCREATOR__H


namespace state {
  class Element;
  class IElement;
  class Fowl;
}

#include "IElement.h"
#include "Fowl.h"

namespace state {

  /// class FowlCreator - 
  class FowlCreator : public state::IElement {
    // Operations
  public:
    Element* create ();
  };

};

#endif