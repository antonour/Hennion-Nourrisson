/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>
using namespace std;

namespace engine{
    
    Ruler::Ruler (ActionList* a, state::State* s, CommandSet* c){
         this->actions=a;
         this->currentState=s;
         this->commands=c;
    }
    
    
    Ruler::~Ruler (){}
    
    void Ruler::collisions (){}
    
    void Ruler::apply (){
        /*if (this->commands->commands[1]){
            KillCommand* k;
            k=reinterpret_cast<KillCommand*>(this->commands->commands[1]);
            this->actions->add(new KillFowl(k->getIDX()));
        }
        if (this->commands->commands[0]){
            MoveCommand* m;
            m=reinterpret_cast<MoveCommand*>(this->commands->commands[0]);
            if (m->getMoveID()==MoveID::CHICKEN){
                cout << "apply" << endl;
                this->actions->add(new MoveFowl(m->getIDX(),m->getDir()));
            }
        }*/
        
        for (Command* cmd : this->commands->commands){
            if (cmd->getCmdTypeID()==CmdTypeID::MOVE_CMD){
                MoveCommand* m;
                m=reinterpret_cast<MoveCommand*>(cmd);
                if (m->getMoveID()==MoveID::CHICKEN){
                this->actions->add(new MoveFowl(m->getIDX(),m->getDir()));
                }
            }
            if (cmd->getCmdTypeID()==CmdTypeID::KILL_CMD){
                KillCommand* k;
                k=reinterpret_cast<KillCommand*>(this->commands->commands[1]);
                this->actions->add(new KillFowl(k->getIDX()));
            }
        }
        this->actions->apply();
        this->commands->commands.clear();
    }
    
    void Ruler::MoveMyFowl (int idx){
        
    }
    
    void Ruler::MoveMyWeapon (int idx){
        
    }
    
    void Ruler::ZoomInWanted (){
        
    }
    
    void Ruler::ZoomOutWanted (){
        
    }
    
    void Ruler::Shoot (){
        
    }
    
    void Ruler::ChooseMyWeapon (int idx){
        
    }
    
}