/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    FireCommand::FireCommand(int power, int x, int y, bool charging){
        this->power=power;
        this->x=x;
        this->y=y;
        this->charging=charging;
    }
    
    CmdTypeID FireCommand::getCmdTypeID(){
        return CmdTypeID::FIRE_CMD;
    }
    
    bool FireCommand::isCharging(){
        return this->charging;
    }
    
    void FireCommand::setFire(int power, int x, int y, bool charging){
        this->power=power;
        this->x=x;
        this->y=y;
        this->charging=charging;
    }
}