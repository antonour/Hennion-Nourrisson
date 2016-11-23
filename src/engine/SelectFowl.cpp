/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"


namespace engine{
    
    SelectFowl::SelectFowl (int idx, MoveCamera* v, bool TeamChange){
        this->idx=idx;
        this->v=v;
        this->TeamChange=TeamChange;
    }

    
    void SelectFowl::apply (state::State* s, bool notify){
        
        if (this->TeamChange==false){
        
                state::Element* e = s->getMobileElement(this->idx);
                int next=s->selectNextFowl(false);
                state::Element* eNext = s->getMobileElement(next);

                if (e->getTypeID()==state::TypeID::FOWL and eNext->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* f = reinterpret_cast<state::Fowl*>(e);
                    state::Fowl* fNext = reinterpret_cast<state::Fowl*>(eNext);

                    while (f->getFowlColor()!=fNext->getFowlColor()){
                        next=s->selectNextFowl(false);
                        state::Element* eNext2 = s->getMobileElement(next);
                        fNext = reinterpret_cast<state::Fowl*>(eNext2);
                    }
                    
                    this->n->updateIDX(next);                    
                    state::Element* element=s->getMobileElement(next);
                    this->v->setCenter (element->getX(), element->getY());
                    
                    std::vector<state::Element*> listpoule=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();      
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_SELECTED),listpoule,wep);
                }
                
        }
        
        else if (this->TeamChange==true){
            
            state::Element* e = s->getMobileElement(this->idx);
                int next=s->selectNextFowl(false);
                state::Element* eNext = s->getMobileElement(next);

                if (e->getTypeID()==state::TypeID::FOWL and eNext->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* f = reinterpret_cast<state::Fowl*>(e);
                    state::Fowl* fNext = reinterpret_cast<state::Fowl*>(eNext);

                    while (f->getFowlColor()==fNext->getFowlColor()){
                        next=s->selectNextFowl(false);
                        state::Element* eNext2 = s->getMobileElement(next);
                        fNext = reinterpret_cast<state::Fowl*>(eNext2);
                    }
                    
                    this->n->updateIDX(next); 
                    state::Element* element=s->getMobileElement(next);
                    this->v->setCenter (element->getX(), element->getY());
                    
                    std::vector<state::Element*> listpoule=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();      
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_SELECTED),listpoule,wep);
                }
            
        }
        
        
        
        
    }
    
    void SelectFowl::setNextCommand (NextCommand* n){
        this->n=n;
    }
    
    
}