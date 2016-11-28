/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    Command::~Command (){}
    
    void Command::setMoveCamera (MoveCamera* v){
        this->v=v;
    }
    
    MoveCamera* Command::getMoveCamera (){
        return this->v;
    }
    
}