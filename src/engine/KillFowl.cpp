/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

using namespace std;

namespace engine{
    
    KillFowl::KillFowl (int idx){
        this->idx=idx;
    }
    
    KillFowl::KillFowl (int idx, FireCommand* fire){
        this->idx=idx;
        this->fire=fire;
    }
    
    void KillFowl::setIDX(int idx){
        this->idx=idx;
    }
    
    KillFowl::~KillFowl (){}
  
    void KillFowl::apply(state::State* s, bool notify){
        state::Element* elementTueur = s->getMobileElement(this->idx);
        int X=elementTueur->getX();
        int Y=elementTueur->getY();
        state::Fowl* pouleTueuse = reinterpret_cast<state::Fowl*>(elementTueur);
        state::FowlColor col=pouleTueuse->getFowlColor();
        int next;
        next=s->selectNextFowl(true);
        
        while (next!=this->idx){ 
            state::Element* elementTue = s->getMobileElement(next);            
            if (elementTue->getTypeID()==state::TypeID::FOWL){
                state::Fowl* pouleTuee = reinterpret_cast<state::Fowl*>(elementTue);
                if (pouleTuee->getY()==Y && pouleTuee->getFowlColor()!=col){
                    if (pouleTueuse->getFowlStatus()==state::FowlStatus::HITTING){
                        if (pouleTueuse->getDirection()==state::Direction::OUEST){
                            if (pouleTuee->getX() <=X && pouleTuee->getX() >= X-125){
                                pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                if(pouleTuee->getFowlColor()==state::FowlColor::GREEN){
                                    fire->setNbGreenDead(fire->getNbGreenDead()+1);
                                }
                                else{
                                    fire->setNbWhiteDead(fire->getNbWhiteDead()+1);
                                }
                            }
                        }
                        else if (pouleTueuse->getDirection()==state::Direction::EST){
                            if (pouleTuee->getX() >=X && pouleTuee->getX() <= X+125){
                                pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                if(pouleTuee->getFowlColor()==state::FowlColor::GREEN){
                                    fire->setNbGreenDead(fire->getNbGreenDead()+1);
                                }
                                else{
                                    fire->setNbWhiteDead(fire->getNbWhiteDead()+1);
                                }
                            }
                        }
                    }
                }
                s->setMobileElement(pouleTuee,next);
            }
        next=s->selectNextFowl(true);
        }
        if (notify){
            std::vector<state::Element*> listpoule=s->getMobileElements();
            std::vector<state::Weapon*> wep=s->getWeaponElements();      
            s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_DEAD),listpoule,wep);
        }
    }

    
    
}
        