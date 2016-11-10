/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../ia.hpp"
#include "../state.hpp"
#include "../engine.hpp"

namespace ia{
    
    DumbIA::DumbIA (){}
    
    void DumbIA::runDumbIA (state::State& s, engine::MoveFowl* mv, engine::KillFowl* k, engine::MoveCamera* v,int ite){
        int next;
        
        if ((ite>=0 and ite <2) or (ite>=400 and ite<404)){
            next=s.selectNextFowl();
            k->setIDX(next);
            mv->setIDX(next);
            state::Element* e=s.getMobileElement(next);
            mv->setCoords(e->getX(),0,0);
            v->setCenter (e->getX(), e->getY());
        }
        
        else if (ite>=2 and ite <132){
            mv->setDir(state::Direction::OUEST);
            mv->apply(s,true);
        }
        
        else if (ite>=132 and ite<400){
            mv->setDir(state::Direction::EST);
            mv->apply(s,true);
        }
        else {
            k->apply(s,true);
        }
        
    }
    
}