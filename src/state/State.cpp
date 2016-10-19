/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"../state.hpp"

namespace state{
    void State::setElementFactory(ElementFactory* f){
        this->factory=f;
    }

    std::vector<MobileElement*> State::getMobileElements (){
        return this->elements;
    }
    
    MobileElement* State::getMobileElement (int idx){
        return this->elements[idx];
    }
    
    std::vector<StaticElement*> State::getStaticElements (){
        return this->background;
    }
    
    StaticElement* State::getStaticElement (int idx){
        return this->background[idx];
    }
    
}