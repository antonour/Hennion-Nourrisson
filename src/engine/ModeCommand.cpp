/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    ModeCommand::ModeCommand (EngineMode mode){
        this->mode=mode;
    }
    
    int ModeCommand::getCategory () const{
        return MODE_CATEGORY;
    }
    
    CommandTypeID ModeCommand::getTypeID () const{
        return MODE;
    }
    
    EngineMode ModeCommand::getMode () const{
        return this->mode;
    }
    
}