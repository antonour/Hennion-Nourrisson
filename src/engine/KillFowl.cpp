/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    KillFowl::KillFowl (int idx){
        this->idx=idx;
    }
    
    void KillFowl::setIDX(int idx){
        this->idx=idx;
    }
    
    KillFowl::~KillFowl (){}
    

    
    void KillFowl::apply(state::State* s, bool notify){
        state::Element * pouledead;
        pouledead= s->getMobileElement(this->idx);
        if (pouledead->getTypeID()==state::TypeID::FOWL){
            state::Fowl * poule;
            poule=reinterpret_cast<state::Fowl*>(pouledead);
            poule->setFowlStatus(state::FowlStatus::DEAD);
            s->setMobileElement(poule, this->idx);
            if (notify){
                std::vector<state::Element*> listpoule=s->getMobileElements();        
                s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_DEAD),listpoule);
        
            }
        }
    }
}