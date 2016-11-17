/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    
    KillFowl::KillFowl (int idx){
        this->idx=idx;
    }
    
    void KillFowl::setIDX(int idx){
        this->idx=idx;
    }
    
    KillFowl::~KillFowl (){}
  
    void KillFowl::apply(state::State* s, bool notify){
        
        state::Element* elementTueur = s->getMobileElement(this->idx);
        int next;
        next=s->selectNextFowl();
        
        if (elementTueur->getTypeID()==state::TypeID::FOWL){
            while (next!=this->idx){
                state::Fowl* pouleTueuse = reinterpret_cast<state::Fowl*>(elementTueur);
                state::Element* elementTue = s->getMobileElement(next);
            
                if (elementTue->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* pouleTuee = reinterpret_cast<state::Fowl*>(elementTue);
                    if (pouleTuee->getY()==pouleTueuse->getY()){
                        if (pouleTueuse->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                            if ((pouleTueuse->getX())/125==(pouleTuee->getX())/125){
                                if (pouleTueuse->getFowlColor()!=pouleTuee->getFowlColor()){
                                    pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                    s->setMobileElement(elementTue,next);
                                }
                            }
                        }
                        else if (pouleTueuse->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                            if ((pouleTuee->getX()>=(pouleTueuse->getX()-125)) and (pouleTuee->getX()<=pouleTueuse->getX())){
                                if (pouleTueuse->getFowlColor()!=pouleTuee->getFowlColor()){
                                    pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                    s->setMobileElement(elementTue,next);
                                }
                            }                            
                        }
                        else if (pouleTueuse->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                            if ((pouleTuee->getX()<=(pouleTueuse->getX()+125)) and (pouleTuee->getX()>=pouleTueuse->getX())){
                                if (pouleTueuse->getFowlColor()!=pouleTuee->getFowlColor()){
                                    pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                    s->setMobileElement(elementTue,next);
                                }
                            }
                        }
                    }
                }
                
                if (notify){
                std::vector<state::Element*> listpoule=s->getMobileElements();
                std::vector<state::Weapon*> wep=s->getWeaponElements();      
                s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_DEAD),listpoule,wep);
                }
            next=s->selectNextFowl();    
            }
        }
        
        
        
        
    }
        
        
            
             
            
            
            
             
}