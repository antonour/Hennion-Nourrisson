/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    LoadCommand::LoadCommand(bool load){
        this->load=load;
    }
    
    void LoadCommand::setLoad(bool load){
        this->load=load;
    }
    
    CmdTypeID LoadCommand::getCmdTypeID(){
        return CmdTypeID::LOAD_CMD;
    }
}