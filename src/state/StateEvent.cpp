/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"../state.hpp"

namespace state {
    
    StateEvent::~StateEvent(){}
    
    StateEvent::StateEvent(StateEventID id){
        this->stateevent=id;
    }
    
    StateEventID StateEvent::getStateEventID () const{
        return this->stateevent;
    }
    
    void StateEvent::setStateEventID (StateEventID id){
        this->stateevent=id;
    }
}