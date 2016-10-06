// Generated by dia2code
#ifndef STATE__FIELD__H
#define STATE__FIELD__H


namespace state {
  class Element;
  class StaticElement;
}

#include "FieldTypeID.h"
#include "StaticElement.h"

namespace state {

  /// class Field - 
  class Field : public state::StaticElement {
    // Associations
    state::FieldTypeID status;
    // Operations
  public:
    Field (FieldTypeID id);
    bool const isSpace ();
    TypeID const getTypeID ();
    FieldTypeID const getFieldTypeID ();
    void setFieldTypeID (FieldTypeID id);
    Element* const clone ();
    bool const equals (const Element& other);
  };

};

#endif