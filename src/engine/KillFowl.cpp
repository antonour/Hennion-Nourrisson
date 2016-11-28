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
        state::Element* elementTueur = s->getMobileElement(this->idx);
        int X=elementTueur->getX();
        int Y=elementTueur->getY();
        state::Fowl* pouleTueuse = reinterpret_cast<state::Fowl*>(elementTueur);
        state::FowlColor col=pouleTueuse->getFowlColor();
        int next;
        next=s->selectNextFowl(true);
        int i=0;
        bool allkilled=false;
        
        while ((next!=this->idx or i<8) && !allkilled ){
            
            state::Element* elementTue = s->getMobileElement(next);            
            if (elementTue->getTypeID()==state::TypeID::FOWL){
                state::Fowl* pouleTuee = reinterpret_cast<state::Fowl*>(elementTue);
                i++;
                if (pouleTuee->getY()==Y && pouleTuee->getFowlColor()!=col && pouleTuee->getFowlStatus()!=state::FowlStatus::DEAD){
                    if (pouleTueuse->getFowlStatus()==state::FowlStatus::HITTING){
                        if (pouleTueuse->getDirection()==state::Direction::OUEST){
                            if (pouleTuee->getX() <=X && pouleTuee->getX() >= X-125){
                                if (pouleTueuse->getFowlColor()!=pouleTuee->getFowlColor()){
                                    pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                    if(pouleTuee->getFowlColor()==state::FowlColor::GREEN){
                                        s->setNbGreenDead(s->getNbGreenDead()+1);
                                        cout << s->getNbGreenDead() << endl;
                                    }
                                    else{
                                        s->setNbWhiteDead(s->getNbWhiteDead()+1);
                                        cout << s->getNbWhiteDead() << endl;
                                    }
                                }
                            }
                        }
                        else if (pouleTueuse->getDirection()==state::Direction::EST){
                            if (pouleTuee->getX() >=X && pouleTuee->getX() <= X+125){
                                if (pouleTueuse->getFowlColor()!=pouleTuee->getFowlColor()){
                                    pouleTuee->setFowlStatus(state::FowlStatus::DEAD);
                                    if(pouleTuee->getFowlColor()==state::FowlColor::GREEN){
                                        s->setNbGreenDead(s->getNbGreenDead()+1);
                                        cout << s->getNbGreenDead() << endl;
                                    }
                                    else{
                                        s->setNbWhiteDead(s->getNbWhiteDead()+1);
                                        cout << s->getNbWhiteDead() << endl;
                                    }
                                }
                            }
                        }
                    }
                }
                s->setMobileElement(pouleTuee,next);
            }
            if (s->getNbGreenDead()==4 || s->getNbWhiteDead()==4){
                cout <<"TOUTES MORTES" << endl;
                allkilled=true;
            }
            if (!allkilled){
                next=s->selectNextFowl(true);
            }
        }
        if (notify){
            std::vector<state::Element*> listpoule=s->getMobileElements();
            std::vector<state::Weapon*> wep=s->getWeaponElements();      
            s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_DEAD),listpoule,wep);
            if (allkilled){
                s->notifyObservers(new state::StateEvent(state::StateEventID::TEAM_WIN),listpoule,wep);
            }
        }
    }
}
        