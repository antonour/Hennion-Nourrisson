/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    bool StaticElement::isStatic () const{
        return true;
    }
    
    //StaticElement::~StaticElement(){}
}