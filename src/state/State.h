// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H

#include <vector>
#include <string>

namespace state {
  class Element;
  class ElementFactory;
  class Observable;
  class StaticElement;
  class MobileElement;
}

#include "Observable.h"
#include "StaticElement.h"
#include "ElementFactory.h"
#include "MobileElement.h"

namespace state {

  /// class State - 
  class State : public state::Observable {
    // Associations
    // Attributes
  protected:
    std::vector<Element*> elements;
    ElementFactory* factory;
    std::vector<Element*> background;
    // Operations
  public:
    void setElementFactory (ElementFactory* f);
    std::vector<Element*> getMobileElements ();
    Element* getMobileElement (int idx);
    std::vector<Element*> getStaticElements ();
    Element* getStaticElement (int idx);
    void loadLevel (const std::string& file_name);
    void loadChar (const std::string& file_name);
    virtual ~State ();
  };

};

#endif
