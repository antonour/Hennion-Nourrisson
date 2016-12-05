/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"

namespace engine{
    
    SwitchCommand::SwitchCommand (int idx, int idw){
        this->idx=idx;
        this->idWeapon=idw;
    }
    
    CmdTypeID SwitchCommand::getCmdTypeID (){
        return SWITCH_CMD;
    }
    
    void SwitchCommand::setIDX (int idx){
        this->idx=idx;
    }
    
    int SwitchCommand::getIDX (){
        return this->idx;
    }
    
    void SwitchCommand::setIDw (int idw){
        this->idWeapon=idw;
    }
    
    int SwitchCommand::getIDw (){
        return this->idWeapon;
    }    
}