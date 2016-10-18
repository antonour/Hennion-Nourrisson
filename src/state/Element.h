// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <stdlib.h>

#include "TypeID.h"

namespace state {

  // Interface
  /// class Element - 
  class Element {
    // Associations
    state::TypeID type;
    // Attributes
  protected:
    size_t X;
    size_t Y;
    // Operations
  public:
    Element ();
    virtual ~Element ();
    virtual TypeID getTypeID () const = 0;
    int getX () const;
    int getY () const;
    void setX (int x);
    void setY (int y);
    virtual bool isStatic () const = 0;
  };

};

#endif
