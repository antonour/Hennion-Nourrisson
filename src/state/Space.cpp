/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Space::Space (SpaceTypeID id){
        this->status=id;
        this->type=TypeID::SPACE;
    }
    
    Space::~Space(){}
    
    bool Space::isSpace () const{
        return true;
    }
    
    TypeID Space::getTypeID () const{
        return this->type;
    }
    
    SpaceTypeID Space::getSpaceTypeID (){
        return this->status;
    }
    
    void Space::setSpaceTypeID (SpaceTypeID id){
        this->status=id;
    }
    
}