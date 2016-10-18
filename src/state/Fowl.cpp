/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{

    Fowl::Fowl (){
    this->HP=100;    
    }
    
    bool Fowl::isFowl () const{
        return true;
    }
    
    TypeID Fowl::getTypeID () const{
        return FOWL;
    }
    
    int Fowl::getHP (){
        return this->HP;
    }
    
    void Fowl::setHP (int hp){
        this->HP=hp;
    }
    
    FowlStatus Fowl::getFowlStatus () const{
        return this->status;
    }
    
    void Fowl::setFowlStatus (FowlStatus status){
        this->status=status;
    }
    
   
}
