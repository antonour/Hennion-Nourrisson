// Generated by dia2code
#ifndef STATE__WEAPONCREATOR__H
#define STATE__WEAPONCREATOR__H


namespace state {
  class Element;
  class IElement;
  class Weapon;
}

#include "IElement.h"
#include "Weapon.h"

namespace state {

  /// class WeaponCreator - 
  class WeaponCreator : public state::IElement {
    // Operations
  public:
    Element* create ();
  };

};

#endif
