/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "../ia.hpp"
#include "../state.hpp"
#include "../engine.hpp"
#include <stdlib.h>

namespace ia{
    HeuristicIA::HeuristicIA(){}
    
    engine::Command* HeuristicIA::runHeuristicIA(state::State* s, int idx){
        srand(time(NULL));
        int r=rand()%2 + 1;
        engine::Command* cmd;
        
        state::Element * el= s->getMobileElement(idx);
        state::Fowl * poule=reinterpret_cast<state::Fowl*>(el);
        int X=el->getX();
        int Y=el->getY();
        int i=0;
        state::FowlColor FC= poule->getFowlColor();
        for (state::Element* e : s->getMobileElements()){
            state::Fowl* p=reinterpret_cast<state::Fowl*>(e);
            if (i!=idx){
                if (p->getX() <= X+50 && p->getX() >= X-50 && p->getY()==Y){
                    if (p->getFowlColor()!=state::FowlColor::BLANK && p->getFowlColor()!=FC){
                        s->killFowl();
                        //engine::Command* hit=new engine::FireCommand();
                        //cmd=hit;
                    }
                }
                if (p->getX() <= X+1000 && p->getX() >= X-1000 && p->getY()==Y){
                    if (p->getFowlColor()!=state::FowlColor::BLANK && p->getFowlColor()!=FC){
                        if (p->getX() < X){
                            engine::Command* moveright=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
                            cmd=moveright;
                        }
                        else{
                            engine::Command* moveleft=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
                            cmd=moveleft;
                        }
                    }
                }
                
                else{
                    if (r==1){
                        engine::Command* moveleft=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
                        cmd=moveleft;
                    }
                    else if (r==2){
                        engine::Command* moveright=new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
                        cmd=moveright;
                    }
                }
            }
        }
        return cmd;
    }
}