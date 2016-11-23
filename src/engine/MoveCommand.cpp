/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    
    MoveCommand::MoveCommand(int dx, int dy, MoveID id, int idx, state::Direction d){
        this->DX=dx;
        this->DY=dy;
        this->moveID=id;
        this->idx=idx;
        this->d=d;
    }
    
    MoveID MoveCommand::getMoveID(){
        return this->moveID;
    }
    
    CmdTypeID MoveCommand::getCmdTypeID(){
        return CmdTypeID::MOVE_CMD;
    }
    
    void MoveCommand::setMove(int DX, int DY, int idx, state::Direction d){
        this->DX=DX;
        this->DY=DY;
        this->idx=idx;
        this->d=d;
    }
    
    void MoveCommand::setMoveID(MoveID id){
        this->moveID=id;
    }
    
    void MoveCommand::setIDX(int idx){
        this->idx=idx;
    }
    
    int MoveCommand::getIDX(){
        return this->idx;
    }
    
    state::Direction MoveCommand::getDir(){
        return this->d;
    }
}
