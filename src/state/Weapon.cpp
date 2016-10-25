/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Weapon::Weapon (WeaponStatus status){
        this->power=1;
        this->weight=10;
        this->ammo=32;
        this->status=status;
        
    }
    
    bool Weapon::isFowl () const{
        return false;
    }
    
    TypeID Weapon::getTypeID () const{
        return WEAPON;
    }
    
    int Weapon::getPower () const{
        return this->power;  
    }
    
    int Weapon::getWeight () const{
        return this->weight;
    }
    
    void Weapon::setPower (int power){
        this->power=power;
    }
    
    void Weapon::setWeight (int weight){
        this->weight=weight;
    }
    
    WeaponStatus Weapon::getWeaponStatus () const{
        return this->status;
    }
    
    void Weapon::setWeaponStatus (WeaponStatus status){
        this->status=status;
    }
    
}
