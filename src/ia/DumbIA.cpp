/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../ia.hpp"
#include "../state.hpp"
#include "../engine.hpp"
#include <stdlib.h>
#include <time.h>

namespace ia{
    
    DumbIA::DumbIA (state::State* currentState): AI(currentState) {
        this->futurState=currentState;
    }
    
    engine::Command* DumbIA::run (state::State* s){
        srand(time(NULL));
        int r=rand()%4 + 1;
        int idx=s->getSelected();
        engine::Command* cmd;
      
        if (r==1){
            engine::Command* moveleft=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
            cmd=moveleft;
            return cmd;
        }
        
        else if (r==2){
            engine::Command* moveright=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
            cmd=moveright;
            return cmd;
        }
        
        else if (r==3){
            engine::Command* jumpleft= new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_JUMP,idx,state::Direction::OUEST);
            cmd=jumpleft;
            return cmd;
        }
        
        else{
            engine::Command* jumpright= new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_JUMP,idx,state::Direction::EST);
            cmd=jumpright;
            return cmd;
        }
    }
    
}