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
    
    void MoveFowl::Jump (state::State& s, bool notify){
        /*
        state::Fowl* bla;
        state::Element * el=s.getMobileElement(this->idx);   
        
        
        int ddx, iddx;
        
        
        state::Element* elgauche;
        state::Element* eldroit;        
        
        if (this->dx>el->getX()){
            ddx=this->dx-el->getX();
            iddx=ddx/125;
            state::Element* egauche=s.getStaticElement(this->idx-(iddx+1)+40*this->dy);
            state::Element* edroit=s.getStaticElement(this->idx+(iddx-1)+40*this->dy);
            elgauche=egauche;
            eldroit=edroit;
        }
        else if (this->dx<el->getX()){
            ddx=el->getX()-this->dx;
            iddx=ddx/125;
            state::Element* egauche=s.getStaticElement(this->idx-(iddx-1)+40*this->dy);
            state::Element* edroit=s.getStaticElement(this->idx+(iddx+1)+40*this->dy);
            elgauche=egauche;
            eldroit=edroit;
        }
        else{
            state::Element* egauche=s.getStaticElement(this->idx-1);
            state::Element* edroit=s.getStaticElement(this->idx+1);
            elgauche=egauche;
            eldroit=edroit;
        }
             
            state::Field* fgauche;
            fgauche=reinterpret_cast<state::Field*>(elgauche);
                
            state::Field* fdroit;
            fdroit=reinterpret_cast<state::Field*>(eldroit);
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            if (this->Direction==state::Direction::OUEST){
                if (fgauche->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setX(bla->getX()-125);}
                else{
                    bla->setX(bla->getX()-125);
                    bla->setY(bla->getY()-97);}
                s.setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s.getMobileElements();
                    std::vector<state::Weapon*> wep=s.getWeaponElements();
                    s.notifyObservers(new state::StateEvent(state::StateEventID::FOWL_JUMP_LEFT),list,wep);
                }
            }
            if (this->Direction==state::Direction::EST){
                if (fdroit->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setX(bla->getX()+125);}
                else{
                    bla->setX(bla->getX()+125);
                    bla->setY(bla->getY()-97);}
                s.setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s.getMobileElements();
                    std::vector<state::Weapon*> wep=s.getWeaponElements();
                    s.notifyObservers(new state::StateEvent(state::StateEventID::FOWL_JUMP_RIGHT),list,wep);
                }
            }}*/
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
            if (this->Direction==state::Direction::OUEST){ //and fgauche->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setFowlStatus(state::FowlStatus::ALIVE_LEFT);
                s->setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_MOVE_LEFT),list,wep);
                }
            }
            if (this->Direction==state::Direction::EST){ //and fdroit->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setFowlStatus(state::FowlStatus::ALIVE_RIGHT);
                s->setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s->getMobileElements();
                    std::vector<state::Weapon*> wep=s->getWeaponElements();
                    s->notifyObservers(new state::StateEvent(state::StateEventID::FOWL_MOVE_RIGHT),list,wep);
                }
            }
        }
    }
    
    }