/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    MobileElement::MobileElement (){
        this->direction=NONE;
    }
    
    bool MobileElement::isStatic () const{
        return false;
    }
    
    Direction MobileElement::getDirection () const{
        return this->direction;
    }
    
    void MobileElement::setDirection (Direction dir){
        this->direction=dir;
    }

}
