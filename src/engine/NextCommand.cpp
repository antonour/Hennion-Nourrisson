/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"

namespace engine{
    
    NextCommand::NextCommand(int idx, MoveCamera* v, MoveFowl* mv, KillCommand* KC, bool TeamChange, bool FowlHasMoved){
        this->idx=idx;
        this->v=v;
        this->mv=mv;
        this->KC=KC;
        this->TeamChange=TeamChange;
        this->FowlHasMoved=FowlHasMoved;
    }
    
    CmdTypeID NextCommand::getCmdTypeID (){
        return CmdTypeID::NEXT_CMD;
    }
    
    int NextCommand::getIDX (){
        return this->idx;
    }
    
    MoveCamera* NextCommand::getMoveCamera (){
        return this->v;
    }
    
    MoveFowl* NextCommand::getMoveFowl (){
        return this->mv;
    }
    
    KillCommand* NextCommand::getKillCommand (){
        return this->KC;
    }
    
    void NextCommand::setNextCommand(int idx, MoveCamera* v, MoveFowl* mv, KillCommand* KC, bool TeamChange, bool FowlHasMoved){
        this->idx=idx;
        this->v=v;
        this->mv=mv;
        this->KC=KC;
        this->TeamChange=TeamChange;
        this->FowlHasMoved=FowlHasMoved;
    }
    
    
    bool NextCommand::getTeamChange (){
        return this->TeamChange;
    }
    
    void NextCommand::setIDX (int idx){
        this->idx=idx;
    }
    
    bool NextCommand::getFowlHasMoved (){
        return this->FowlHasMoved;
    }
    
    void NextCommand::setFowlHasMoved (bool FowlHasMoved){
        this->FowlHasMoved=FowlHasMoved;
    }
    
    void NextCommand::setTeamChange (bool TeamChange){
        this->TeamChange=TeamChange;
    }
    
    void NextCommand::updateIDX (int idx){
        this->idx=idx;
        this->mv->setIDX(idx);
        this->KC->setIDX(idx);
    }
    
}
