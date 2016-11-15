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
                    while(isFalling(this->currentState,m)){}
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
    
    bool Ruler::isMovable (state::State* s, MoveCommand* m){
        return true;
    }
    
    bool Ruler::isFalling (state::State* s, MoveCommand* m){
        state::Fowl* bla;
        state::Element * el=s->getMobileElement(m->getIDX());
        
        if (el->getTypeID()==state::TypeID::FOWL){
        bla=reinterpret_cast<state::Fowl*>(el);
            state::Element* e=s->getStaticElement(m->getIDX());
            e->setX(el->getX());
            e->setY(el->getY()+97);
            int idx;
            if (bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                idx = e->getIDXbyXY()+1;
            }
            else{
                idx = e->getIDXbyXY();
            }
            std::cout<<e->getX()<<std::endl;
            std::cout<<e->getY()<<std::endl;
            std::cout<<e->getIDXbyXY()<<std::endl;

            state::Element* ebas=s->getStaticElement(idx);

            state::Field* fbas;
            fbas=reinterpret_cast<state::Field*>(ebas);

            if (fbas->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setY(bla->getY()+97);
                s->setMobileElement(bla,m->getIDX());
                std::vector<state::Element*> list=s->getMobileElements();
                std::vector<state::Weapon*> wep=s->getWeaponElements();
                s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_FALL),list,wep);                            
                return true;
            }
            else{
                return false;
            }}
        return false;
        
       }
        
    
    
}