/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "../ia.hpp"
#include "../state.hpp"
#include "../engine.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

namespace ia{
    HeuristicIA::HeuristicIA(state::State* currentState):DumbIA(currentState){}
    
    std::map<int,int> HeuristicIA::givePonderation(){
        std::map<int,int> tri;
        tri[1]=0;
        tri[2]=0;
        
        int idx=this->currentState->getSelected();
        
        state::Element * el= this->currentState->getMobileElement(idx);
        state::Fowl * poule=reinterpret_cast<state::Fowl*>(el);
        
        int X=el->getX();
        int Y=el->getY();
        
        state::FowlColor FC= poule->getFowlColor();
        
        for (state::Element* e : this->currentState->getMobileElements()){
            state::Fowl* p=reinterpret_cast<state::Fowl*>(e);
            if (p->isSelected()!=true){
                if (p->getX() <= X+50 && p->getX() >= X-50 && p->getY()==Y && p->getFowlStatus()!=state::FowlStatus::DEAD){
                    if (p->getFowlColor()!=state::FowlColor::BLANK && p->getFowlColor()!=FC){
                        if (p->getDirection()==state::Direction::EST){
                            tri[1]=10;
                        }
                        else tri[1]=11;
                        return tri;
                    }
                }
                if (p->getX() <= X+1000 && p->getX() >= X-1000 && p->getY()==Y && p->getFowlStatus()!=state::FowlStatus::DEAD){
                    if (p->getFowlColor()!=state::FowlColor::BLANK && p->getFowlColor()!=FC){
                        if (p->getX() < X){
                            tri[2]=5;
                        }
                        else if (p->getX() > X){
                            tri[2]=6;
                        }
                        return tri;
                    }
                }
            }
        }
        return tri;
    }
    
    engine::Command* HeuristicIA::run(state::State* s){
        std::map<int,int> pond=this->givePonderation();
        if (pond[1]!=0){
            if (pond[1]==10){
                return new engine::FireCommand(this->currentState->getSelected(),state::Direction::EST);
            }
            if (pond[1]==11){
                return new engine::FireCommand(this->currentState->getSelected(),state::Direction::OUEST);
            }
        }
        if (pond[2]!=0){
            if (pond[2]==5){
                return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,this->currentState->getSelected(),state::Direction::OUEST);
            }
            if (pond[2]==6){
                return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,this->currentState->getSelected(),state::Direction::EST);
            }
        }
        
        return DumbIA::run(s,this->currentState->getSelected());
    }
}