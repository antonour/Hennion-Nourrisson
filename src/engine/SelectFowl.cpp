/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"


namespace engine{
    
    SelectFowl::SelectFowl (NextCommand* NC){
        this->NC=NC;
    }
    
    void SelectFowl::apply (state::State* s, bool notify){
        
        if (NC->getTeamChange()==false){
        
                state::Element* e = s->getMobileElement(NC->getIDX());
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
                    
                    NC->setIDX(next);
                    NC->getKillCommand()->setIDX(next);
                    NC->getMoveFowl()->setIDX(next);
                    state::Element* element=s->getMobileElement(next);
                    NC->getMoveCamera()->setCenter (element->getX(), element->getY());
                }
                
        }
        
        else if (NC->getTeamChange()==true){
            
            state::Element* e = s->getMobileElement(NC->getIDX());
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
                    NC->setIDX(next);
                    NC->getKillCommand()->setIDX(next);
                    NC->getMoveFowl()->setIDX(next);
                    state::Element* element=s->getMobileElement(next);
                    NC->getMoveCamera()->setCenter (element->getX(), element->getY());
                }
            
        }
        
        
        
        
    }
    
    
}