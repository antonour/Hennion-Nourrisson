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
                while(isFalling(this->currentState,m)){}
                if (isMovable(this->currentState,m)){
                    if (m->getMoveID()==MoveID::CHICKEN_WALK){      
                        this->actions->add(new MoveFowl(m->getIDX(),m->getDir()));
                        }
                    else if (m->getMoveID()==MoveID::CHICKEN_JUMP and canJumpOver(this->currentState,m)){
                        this->actions->add(new FowlJump(m->getIDX()));
                    }
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
                
        state::Fowl* bla;
        state::Element * el=s->getMobileElement(m->getIDX());
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            state::Element* e=s->getStaticElement(m->getIDX());
            
            e->setY(el->getY());
            int idx;
            
            if (bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT and m->getDir()==state::Direction::OUEST){
                e->setX(el->getX()-125);
                idx = e->getIDXbyXY()+1;
            }
            else if (bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT and m->getDir()==state::Direction::EST){
                e->setX(el->getX()+125);
                idx = e->getIDXbyXY();
            }
            else{
                return true;
            }
            
            state::Element* elateral=s->getStaticElement(idx);
            
            if (elateral->getTypeID()==state::TypeID::FIELD){
                state::Field* flateral = reinterpret_cast<state::Field*>(elateral);
                if (flateral->getFieldTypeID()==state::FieldTypeID::NEANT){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }    
        
        }
        else{
            return false;
        }
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
        
    bool Ruler::canJumpOver (state::State* s, MoveCommand* m){
        
        state::Fowl* bla;
        state::Element * el=s->getMobileElement(m->getIDX());
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            state::Element* e=s->getStaticElement(m->getIDX());
            
            int idx;
            
            if (bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT and m->getDir()==state::Direction::OUEST){
                e->setX(el->getX()-125);
                e->setY(el->getY()-97);
                idx = e->getIDXbyXY()+1;
            }
            else if (bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT and m->getDir()==state::Direction::EST){
                e->setX(el->getX()+125);
                e->setY(el->getY()-97);
                idx = e->getIDXbyXY();
            }
            else{
                return true;
            }
            
            state::Element* elateralhaut=s->getStaticElement(idx);
            
            if (elateralhaut->getTypeID()==state::TypeID::FIELD){
                state::Field* flateralhaut = reinterpret_cast<state::Field*>(elateralhaut);
                if (flateralhaut->getFieldTypeID()==state::FieldTypeID::NEANT){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            
            }
            else{
                return false;
            }
        }
    
}