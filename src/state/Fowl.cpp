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
    }
    
    bool Fowl::isFowl () const{
        return true;
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
    
   
}
