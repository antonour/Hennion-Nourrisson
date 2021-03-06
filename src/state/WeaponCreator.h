// Generated by dia2code
#ifndef STATE__WEAPONCREATOR__H
#define STATE__WEAPONCREATOR__H


namespace state {
  class Element;
  class IElement;
  class Weapon;
}

#include "WeaponStatus.h"
#include "IElement.h"
#include "Weapon.h"

namespace state {

  /// class WeaponCreator - 
  class WeaponCreator : public state::IElement {
    // Attributes
  private:
    WeaponStatus status;
    bool visible;
    // Operations
  public:
    Element* create ();
    WeaponCreator (WeaponStatus status, bool visible);
  };

};

#endif
