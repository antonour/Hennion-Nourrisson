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
    
    DumbIA::DumbIA (){}
    
    engine::Command* DumbIA::runDumbIA (state::State* s,int idx){
        srand(time(NULL));
        int r=rand()%2 + 1;
        engine::Command* cmd;
      
        if (r==1){
            engine::Command* moveleft=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
            cmd=moveleft;
        }
        
        else if (r==2){
            engine::Command* moveright=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
            cmd=moveright;
        }
        
        else if (r==3){
            engine::Command* jumpleft= new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_JUMP,idx,state::Direction::OUEST);
            cmd=jumpleft;
        }
        
        else if (r==4){
            engine::Command* jumpright= new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_JUMP,idx,state::Direction::EST);
            cmd=jumpright;
        }
        
        return cmd;
    }
    
}