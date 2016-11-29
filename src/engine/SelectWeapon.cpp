/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    
    SelectWeapon::SelectWeapon (int idx, int idWeapon){
        this->idx=idx;
        this->idWeapon=idWeapon;
    }
    
    void SelectWeapon::apply (state::State* s, bool notify){
        
        state::Element* e = s->getMobileElement(this->idx);
        
        if (e->getTypeID()==state::TypeID::FOWL){
            
            state::Fowl* f = reinterpret_cast<state::Fowl*>(e);
            
            if (this->idWeapon==0){
                f->setFowlWeapon(state::FowlWeapon::CHAINSAW);
            }
            else if (this->idWeapon==1){
                f->setFowlWeapon(state::FowlWeapon::LIGHTSABER);
            }
            else if (this->idWeapon==2){
                f->setFowlWeapon(state::FowlWeapon::AXE);
            }
            else if (this->idWeapon==3){
                f->setFowlWeapon(state::FowlWeapon::SWORD);
            }
            else if (this->idWeapon==4){
                f->setFowlWeapon(state::FowlWeapon::NINJASABER);
            }
            else if (this->idWeapon==5){
                f->setFowlWeapon(state::FowlWeapon::SOCKET);
            }
            else if (this->idWeapon==6){
                f->setFowlWeapon(state::FowlWeapon::MAGICWAND);
            }
            else{
                std::cout<<"Erreur Select Weapon"<<std::endl;
            }
            
            std::vector<state::Element*> listpoule=s->getMobileElements();
            std::vector<state::Weapon*> wep=s->getWeaponElements();      
            s->notifyObservers(new state::StateEvent(state::StateEventID::WEAPON_SWITCHED),listpoule,wep);            
            
        }
        
    }
    
}
