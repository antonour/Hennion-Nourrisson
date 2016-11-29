/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{

    Fowl::Fowl (FowlColor color,FowlStatus status){
    this->HP=100;
    this->color=color;
    this->status=status;
    this->type=TypeID::FOWL;
    this->selected=false;
    this->weapon=FowlWeapon::SWORD;
    }
    
    bool Fowl::isFowl () const{
        return true;
    }
    
    void Fowl::setMoveUnits(int units){
        this->moveunits=units;
    }
    
    int Fowl::getMU(){
        return this->moveunits;
    }
    
    TypeID Fowl::getTypeID () const{
        return this->type;
    }
    
    int Fowl::getHP (){
        return this->HP;
    }
    
    void Fowl::setHP (int hp){
        this->HP=hp;
    }
    
    FowlStatus Fowl::getFowlStatus (){
        return this->status;
    }
    
    void Fowl::setFowlStatus (FowlStatus status){
        this->status=status;
    }
    
    FowlColor  Fowl::getFowlColor (){
        return this->color;
    }
    
    void Fowl::setFowlColor (FowlColor color){
        this->color=color;
    }
    
    bool Fowl::isSelected(){
        return this->selected;
    }
    
    void Fowl::setSelected(bool sel){
        this->selected=sel;
    }
    
    void Fowl::setFowlWeapon (FowlWeapon weapon){
        this->weapon=weapon;
    }
    
    FowlWeapon Fowl::getFowlWeapon (){
        return this->weapon;
    }
   
}
