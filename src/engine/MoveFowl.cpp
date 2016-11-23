/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include "SelectFowl.h"
#include <iostream>

using namespace std;

namespace engine{
    
    MoveFowl::MoveFowl (int idx){
        this->idx=idx;
    }
    
    MoveFowl::MoveFowl (int idx, state::Direction d){
        this->idx=idx;
        this->Direction=d;
    }
    
    MoveFowl::~MoveFowl (){}
    
    void MoveFowl::setCoords (int dx, int dy, int dpos){
        this->dx=dx;
        this->dy=dy;
        this->dpos=dpos;               
    }
    
    void MoveFowl::setDir (state::Direction direction){
        this->Direction=direction;
    }        
    
    void MoveFowl::setIDX(int idx){
        this->idx=idx;
    }
    
    int MoveFowl::getIDX(){
        return this->idx;
    }
    
    void MoveFowl::setFowl(state::Fowl* f){
        this->poule=f;
    }
    
    state::Fowl* MoveFowl::getFowl(){
        return this->poule;
    }
     
    void MoveFowl::apply(state::State* s, bool notify){
        state::Fowl* bla;
        state::Element * el=s->getMobileElement(this->idx);
        
        
        
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            if (this->Direction==state::Direction::OUEST){
                int moverestants=bla->getMU();
                if (moverestants>0){
                    bla->setFowlStatus(state::FowlStatus::ALIVE_LEFT);
                    bla->setDirection(state::Direction::OUEST);
                    bla->setX(bla->getX()-2);
                    bla->setMoveUnits(moverestants-1);
                    s->setMobileElement(bla,this->idx);
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_MOVE_LEFT),list,wep);                
                }
                else{
                    bla->setFowlStatus(state::FowlStatus::ALIVE_FACE);
                    s->setMobileElement(bla,this->idx);
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_STOP),list,wep);
                    
                        //changement de poule
                      state::Element* e = s->getMobileElement(this->idx);
                        int next=s->selectNextFowl(false);
                        state::Element* eNext = s->getMobileElement(next);

                        if (e->getTypeID()==state::TypeID::FOWL and eNext->getTypeID()==state::TypeID::FOWL){
                            state::Fowl* f = reinterpret_cast<state::Fowl*>(e);
                            state::Fowl* fNext = reinterpret_cast<state::Fowl*>(eNext);

                            while (f->getFowlColor()==fNext->getFowlColor()){
                                next=s->selectNextFowl(false);
                                state::Element* eNext2 = s->getMobileElement(next);
                                fNext = reinterpret_cast<state::Fowl*>(eNext2);
                            }
                                                       
                        }
                        
                    state::Element* element=s->getMobileElement(next);
                    this->v->setCenter(element->getX(),element->getY());
                        
                }
            }
            if (this->Direction==state::Direction::EST){
                int moverestants=bla->getMU();
                if (moverestants>0){
                    bla->setFowlStatus(state::FowlStatus::ALIVE_RIGHT);
                    bla->setX(bla->getX()+2);
                    bla->setMoveUnits(moverestants-1);
                    bla->setDirection(state::Direction::EST);
                    s->setMobileElement(bla,this->idx);
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_MOVE_RIGHT),list,wep);                
                }
                else{
                    bla->setFowlStatus(state::FowlStatus::ALIVE_FACE);
                    s->setMobileElement(bla,this->idx);
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_STOP),list,wep); 
                    
                    //Changement de poule
                        state::Element* e = s->getMobileElement(this->idx);
                        int next=s->selectNextFowl(false);
                        state::Element* eNext = s->getMobileElement(next);

                        if (e->getTypeID()==state::TypeID::FOWL and eNext->getTypeID()==state::TypeID::FOWL){
                            state::Fowl* f = reinterpret_cast<state::Fowl*>(e);
                            state::Fowl* fNext = reinterpret_cast<state::Fowl*>(eNext);

                            while (f->getFowlColor()==fNext->getFowlColor()){
                                next=s->selectNextFowl(false);
                                state::Element* eNext2 = s->getMobileElement(next);
                                fNext = reinterpret_cast<state::Fowl*>(eNext2);
                            }
                        }
                
                    state::Element* element=s->getMobileElement(next);
                    this->v->setCenter(element->getX(),element->getY());
                }
            }
        }
    
    }
    
    
    void MoveFowl::setMoveCamera (MoveCamera* v){
        this->v=v;
    }
    
    MoveCamera* MoveFowl::getMoveCamera (){
        return this->v;
    }
    
    
    
}