/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"
#include "../engine.hpp"

namespace engine{
    
    FowlJump::FowlJump (int idx){
        this->idx=idx;
    }
    
    FowlJump::~FowlJump (){}
    
    void FowlJump::apply (state::State* s, bool notify){
        
        state::Fowl* bla;
        state::Element * el=s->getMobileElement(this->idx);
           
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            
            if (bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                bla->setX(bla->getX()-125);
                bla->setY(bla->getY()-97);
                s->setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_JUMP_LEFT),list,wep);
                }
            }
            else if (bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                bla->setX(bla->getX()+125);
                bla->setY(bla->getY()-97);
                s->setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_JUMP_RIGHT),list,wep);
                }
            }
        }
        
        
    }
    
    
    
}