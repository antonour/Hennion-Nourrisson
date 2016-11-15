/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Weapon::Weapon (WeaponStatus status, bool visible){
        this->power=1;
        this->visible=visible;
        this->ammo=32;
        this->status=status;
        this->type=TypeID::WEAPON;
        
    }
    
    bool Weapon::isFowl () const{
        return false;
    }
    
    TypeID Weapon::getTypeID () const{
        return this->type;
    }
    
    int Weapon::getPower () const{
        return this->power;  
    }
    
    bool Weapon::isVisible (){
        return this->visible;
    }
    
    void Weapon::setPower (int power){
        this->power=power;
    }
    
    void Weapon::setVisibility (bool visible){
        this->visible=visible;
    }
    
    WeaponStatus Weapon::getWeaponStatus (){
        return this->status;
    }
    
    void Weapon::setWeaponStatus (WeaponStatus status){
        this->status=status;
    }
    
}
