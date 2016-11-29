// Generated by dia2code
#ifndef STATE__WEAPON__H
#define STATE__WEAPON__H


namespace state {
  class MobileElement;
}

#include "TypeID.h"
#include "WeaponStatus.h"
#include "MobileElement.h"

namespace state {

  /// class Weapon - 
  class Weapon : public state::MobileElement {
    // Associations
    state::WeaponStatus status;
    // Attributes
  protected:
    int power;
    int ammoGreen;
    int ammoWhite;
    TypeID type;
    bool visible;
    // Operations
  public:
    Weapon (WeaponStatus status, bool visible);
    bool isFowl () const;
    TypeID getTypeID () const;
    int getPower () const;
    void setPower (int power);
    WeaponStatus getWeaponStatus ();
    void setWeaponStatus (WeaponStatus status);
    bool isVisible ();
    void setVisibility (bool visible);
    void setAmmoGreen (int ammo);
    int getAmmoGreen ();
    void setAmmoWhite (int ammo);
    int getAmmoWhite ();
  };

};

#endif
