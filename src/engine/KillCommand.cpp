/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    KillCommand::KillCommand(int idx){
        this->idx=idx;
    }
    
    CmdTypeID KillCommand::getCmdTypeID(){
        return CmdTypeID::KILL_CMD;
    }
    
    void KillCommand::setIDX(int idx){
        this->idx=idx;
    }
    
    int KillCommand::getIDX(){
        return this->idx;
    }
}