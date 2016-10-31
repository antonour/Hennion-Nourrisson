/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    LoadCommand::LoadCommand (const char* f){
        
    }
    
    int LoadCommand::getCategory () const{
        return MAIN_CATEGORY;
    }
    
    CommandTypeID LoadCommand::getTypeID () const{
        return LOAD;
    }
    
    EngineMode LoadCommand::getMode () const{
        return PAUSE;
    }
    
}