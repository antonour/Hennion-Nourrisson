/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    FireCommand::FireCommand (int idx, state::Direction d){
        this->idx=idx;
        this->direction=d;
    }
    
    CmdTypeID FireCommand::getCmdTypeID (){
        return FIRE_CMD;
    }
    
    void FireCommand::setFire (int idx, state::Direction d){
        this->idx=idx;
        this->direction=d;
    }
    
    state::Direction FireCommand::getDirection (){
        return this->direction;
    }
    
    int FireCommand::getIDX (){
        return this->idx;
    }
}