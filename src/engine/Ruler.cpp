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
         this->jumped=false;
    }
    
    
    Ruler::~Ruler (){}
       
    void Ruler::apply (){
        for (Command* cmd : this->commands->commands){
            if (cmd->getCmdTypeID()==CmdTypeID::MOVE_CMD){
                MoveCommand* m;
                m=reinterpret_cast<MoveCommand*>(cmd);
                while(isFalling(this->currentState,m)){}
                    if (m->getMoveID()==MoveID::CHICKEN_WALK and isMovable(this->currentState,m)){      
                        this->actions->add(new MoveFowl(m->getIDX(),m->getDir()));
                        }
                    else if (m->getMoveID()==MoveID::CHICKEN_JUMP and canJumpOver(this->currentState,m)){
                        this->jumped=true;
                        this->actions->add(new FowlJump(m->getIDX()));
                    }
                    else if (m->getMoveID()==MoveID::CAMERA){
                    }
                    
            }
            if (cmd->getCmdTypeID()==CmdTypeID::KILL_CMD){
                KillCommand* k;
                k=reinterpret_cast<KillCommand*>(cmd);
                this->actions->add(new KillFowl(k->getIDX()));
            }
            if (cmd->getCmdTypeID()==CmdTypeID::FIRE_CMD){
                FireCommand* fire;
                fire=reinterpret_cast<FireCommand*>(cmd);
                int index=this->currentState->getSelected();
                state::Element* el=this->currentState->getMobileElement(index);
                state::Fowl* f=reinterpret_cast<state::Fowl*>(el);
                this->actions->add(new Fire(fire->getIDX()));
                if (canHit(this->currentState,fire)){
                    this->actions->add(new KillFowl(fire->getIDX()));
                }
                if ((this->currentState->getNbGreenDead()!=3 || f->getFowlColor()==state::FowlColor::GREEN) && (this->currentState->getNbWhiteDead()!=3 || f->getFowlColor()==state::FowlColor::WHITE)){
                    this->actions->add(new SelectFowl(fire->getIDX(),true));
                }
            }
            if (cmd->getCmdTypeID()==CmdTypeID::NEXT_CMD){
                NextCommand* n;
                n=reinterpret_cast<NextCommand*>(cmd);
                if (n->getFowlHasMoved()==false){
                    this->actions->add(new SelectFowl(n->getIDX(),false));
                }
            }
            
            int id = this->currentState->getSelected();
            state::Element* e = this->currentState->getMobileElement(id);
            cmd->getMoveCamera()->setCenter(e->getX(),e->getY());
            this->actions->add(cmd->getMoveCamera());            
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
            
            if ((bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT || bla->getFowlStatus()==state::FowlStatus::ALIVE_FACE) and m->getDir()==state::Direction::OUEST){
                e->setX(el->getX()-125);
                idx = e->getIDXbyXY()+1;
            }
            else if ((bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT || bla->getFowlStatus()==state::FowlStatus::ALIVE_FACE)  and m->getDir()==state::Direction::EST){
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
            //e->setX(el->getX());
            e->setY(el->getY()+97);
            int idx;
            if (bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT || m->getDir()==state::Direction::OUEST){
                e->setX(el->getX()-50);
                idx = e->getIDXbyXY()+1;
            }
            else if (bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT || m->getDir()==state::Direction::EST){
                e->setX(el->getX()+50);
                idx = e->getIDXbyXY();
            }
            else{
                idx = m->getIDX();
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
    
    void Ruler::resetJump(){
        this->jumped=false;
    }
    
    bool Ruler::canJumpOver (state::State* s, MoveCommand* m){
        
        if (this->jumped==true){
            return false;
        }
        
        state::Fowl* bla;
        state::Element * el=s->getMobileElement(m->getIDX());
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            state::Element* e=s->getStaticElement(m->getIDX());
            
            int idx;
            
            if (bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                e->setX(el->getX()-125);
                e->setY(el->getY()-97);
                idx = e->getIDXbyXY();
            }
            else if (bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                e->setX(el->getX()+125);
                e->setY(el->getY()-97);
                idx = e->getIDXbyXY()+1;
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
    
    bool Ruler::canHit (state::State* s, FireCommand* fire){
        
        state::Element* el=s->getMobileElement(fire->getIDX());           
        state::Fowl* bla=reinterpret_cast<state::Fowl*>(el);
        
        int i=0;

        if (el->getTypeID()==state::TypeID::FOWL){
            
            for (state::Element* element: s->getMobileElements()){
                state::Element* poupoule = s->getMobileElement(i);
                state::Fowl* poule=reinterpret_cast<state::Fowl*>(poupoule);
                                
                if (element->getY()==el->getY()){
                    
                    if ((element->getX()<=(el->getX()+125)) and (element->getX()>=(el->getX()-125))){
                        if (i!=fire->getIDX()){
                            if(poule->getFowlColor()!=state::FowlColor::BLANK){
                                if(bla->getFowlColor()!=poule->getFowlColor()){
                                    if(bla->getFowlStatus()==state::FowlStatus::ALIVE_FACE){
                                        if(bla->getX()/125==poule->getX()/125){
                                            return true;
                                        }}
                                    if(bla->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                                        if((poule->getX()>=(bla->getX()-125)) and (poule->getX()<=bla->getX())){
                                            return true;
                                        }}
                                    if(bla->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                                        if((poule->getX()<=(bla->getX()+125)) and (poule->getX()>=bla->getX())){
                                            return true;
                                        }}
                                    
                            }}
                        }
                    }
                    
                }
                else{}
                i++;
            }
            
            return false;
        }
        else{
            return false;
        }
    }
    
}