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
    
    void KillFowl::setIDX(int idx){
        this->idx=idx;
    }
    
    KillFowl::~KillFowl (){}
  
    void KillFowl::apply(state::State* s, bool notify){
        cout << "apply" << endl;
        state::Element* elementTueur = s->getMobileElement(this->idx);
        int X=elementTueur->getX();
        int Y=elementTueur->getY();
        state::Fowl* pouleTueuse = reinterpret_cast<state::Fowl*>(elementTueur);
        state::FowlColor col=pouleTueuse->getFowlColor();
        cout << pouleTueuse->getDirection() << endl;
        int next;
        next=s->selectNextFowl(true);
        
        while (next!=this->idx){ 
            state::Element* elementTue = s->getMobileElement(next);            
            if (elementTue->getTypeID()==state::TypeID::FOWL){
                state::Fowl* pouleTuee = reinterpret_cast<state::Fowl*>(elementTue);
                if (pouleTuee->getY()==Y && pouleTuee->getFowlColor()!=col){
                    cout << "meme ligne ennemie" << endl;
                    if (pouleTueuse->getFowlStatus()==state::FowlStatus::HITTING){
                        cout << "elle frappe" << endl;
                        if (pouleTueuse->getDirection()==state::Direction::OUEST){
                            if (pouleTuee->getX() <=X && pouleTuee->getX() >= X-125){
                                cout << "TUE" << endl;
                                pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                            }
                        }
                        else if (pouleTueuse->getDirection()==state::Direction::EST){
                            if (pouleTuee->getX() >=X && pouleTuee->getX() <= X+125){
                                pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
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
        