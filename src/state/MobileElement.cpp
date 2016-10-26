/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    MobileElement::MobileElement (){
        this->direction=NONE;
        this->speed=0;
        this->position=0;
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
    
    Orientation MobileElement::getOrientation () const{
        return this->orient;
    }
    void MobileElement::setOrientation (Orientation ori){
        this->orient=ori;
    }
    
    void MobileElement::setSpeed (size_t s){
        this->speed=s;
    }
    
    void MobileElement::setPosition (size_t p){
        this->position=p;
    }
    
}
