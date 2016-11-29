// Generated by dia2code
#ifndef STATE__FOWL__H
#define STATE__FOWL__H


namespace state {
  class MobileElement;
}

#include "TypeID.h"
#include "FowlColor.h"
#include "FowlStatus.h"
#include "FowlWeapon.h"
#include "MobileElement.h"

namespace state {

  /// class Fowl - 
  class Fowl : public state::MobileElement {
    // Associations
    state::FowlWeapon weapon;
    state::FowlColor color;
    state::FowlStatus status;
    // Attributes
  protected:
    /// 		
    int HP;
    TypeID type;
    bool selected;
    int moveunits;
    // Operations
  public:
    Fowl (FowlColor color, FowlStatus status);
    bool isFowl () const;
    TypeID getTypeID () const;
    int getHP ();
    void setHP (int hp);
    FowlStatus getFowlStatus ();
    void setFowlStatus (FowlStatus status);
    FowlColor getFowlColor ();
    void setFowlColor (FowlColor color);
    bool isSelected ();
    void setSelected (bool sel);
    void setMoveUnits (int units);
    int getMU ();
    void setFowlWeapon (FowlWeapon weapon);
    FowlWeapon getFowlWeapon ();
  };

};

#endif
