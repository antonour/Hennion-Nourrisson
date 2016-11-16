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
        /*state::Element * pouledead;
        pouledead= s->getMobileElement(this->idx);
        if (pouledead->getTypeID()==state::TypeID::FOWL){
            state::Fowl * poule;
            poule=reinterpret_cast<state::Fowl*>(pouledead);
            poule->setFowlStatus(state::FowlStatus::DEAD);
            s->setMobileElement(poule, this->idx);
            if (notify){
                std::vector<state::Element*> listpoule=s->getMobileElements();
                std::vector<state::Weapon*> wep=s->getWeaponElements();      
                s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_DEAD),listpoule,wep);
        
            }
        }*/
         state::Element* el=s->getMobileElement(this->idx);           
        state::Fowl* bla=reinterpret_cast<state::Fowl*>(el);
        
        int i=0;

        if (el->getTypeID()==state::TypeID::FOWL){
            
            for (state::Element* element: s->getMobileElements()){
                state::Element* poupoule = s->getMobileElement(i);
                state::Fowl* poule=reinterpret_cast<state::Fowl*>(poupoule);
                                
                if (element->getY()==el->getY()){
                    
                    if ((element->getX()<=(el->getX()+125)) and (element->getX()>=(el->getX()-125))){
                        if (i!=this->idx){
                            if(poule->getFowlColor()!=state::FowlColor::BLANK){
                                if(bla->getFowlColor()!=poule->getFowlColor()){
                                    if(bla->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                                        if(bla->getX()/125==poule->getX()/125){
                                            poule->setFowlStatus(state::FowlStatus::DEAD);
                                            s->setMobileElement(poule,i);
                                        }}
                                    if(bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                                        if((poule->getX()>=(bla->getX()-125)) and (poule->getX()<=bla->getX())){
                                            poule->setFowlStatus(state::FowlStatus::DEAD);
                                            s->setMobileElement(poule,i);
                                        }}
                                    if(bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                                        if((poule->getX()<=(bla->getX()+125)) and (poule->getX()>=bla->getX())){
                                            poule->setFowlStatus(state::FowlStatus::DEAD);
                                            s->setMobileElement(poule,i);
                                        }}
                                    
                            }}
                        }
                    }
                    
                }
                
                if (notify){
                std::vector<state::Element*> listpoule=s->getMobileElements();
                std::vector<state::Weapon*> wep=s->getWeaponElements();      
                s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_DEAD),listpoule,wep);
                }
                
                i++;
            }
            
            
            
        }
    }
        
        
            
             
            
            
            
             
}