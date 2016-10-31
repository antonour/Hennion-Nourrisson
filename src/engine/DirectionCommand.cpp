/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    DirectionCommand::DirectionCommand (int c, state::Direction d){
        this->character=c;
        this->direction=d;
    }
    
    int DirectionCommand::getCategory () const{
        return MOVE_CATEGORY;
    }
    
    CommandTypeID DirectionCommand::getTypeID () const{
        return DIRECTION;
    }
    
    int DirectionCommand::getCharacter () const{
        return this->character;
    }
    
    state::Direction DirectionCommand::getDirection (){
        return this->direction;
    }
    
}
