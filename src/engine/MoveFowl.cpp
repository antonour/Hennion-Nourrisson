/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    
    MoveFowl::MoveFowl (int idx){
        this->idx=idx;
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
    
    void MoveFowl::Jump (int dx, int dy, int dpos){
        
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
   
    void MoveFowl::apply(state::State& s, bool notify){
        state::Fowl* bla;
        state::Element * el=s.getMobileElement(this->idx);   
        
        
        int ddx, iddx;
        
        
        state::Element* elgauche;
        state::Element* eldroit;
        state::Element* elbas;
        
        
        if (this->dx>el->getX()){
            ddx=this->dx-el->getX();
            iddx=ddx/125;
            state::Element* egauche=s.getStaticElement(this->idx-(iddx+1)+40*this->dy);
            state::Element* edroit=s.getStaticElement(this->idx+(iddx-1)+40*this->dy);
            state::Element* ebas=s.getStaticElement((this->idx-iddx)+40*(this->dy+1));
            elgauche=egauche;
            eldroit=edroit;
            elbas=ebas;
            //std::cout<<"go gauche"<<std::endl;
        }
        else if (this->dx<el->getX()){
            ddx=el->getX()-this->dx;
            iddx=ddx/125;
            state::Element* egauche=s.getStaticElement(this->idx-(iddx-1)+40*this->dy);
            state::Element* edroit=s.getStaticElement(this->idx+(iddx+1)+40*this->dy);
            state::Element* ebas=s.getStaticElement((this->idx+iddx)+40*(this->dy+1));
            elgauche=egauche;
            eldroit=edroit;
            elbas=ebas;
            //std::cout<<"go droite"<<std::endl;
        }
        else{
            state::Element* egauche=s.getStaticElement(this->idx-1);
            state::Element* edroit=s.getStaticElement(this->idx+1);
            state::Element* ebas=s.getStaticElement(this->idx+40*(this->dy+1));
            elgauche=egauche;
            eldroit=edroit;
            elbas=ebas;
            //std::cout<<"go surplace"<<std::endl;
        }
             
            state::Field* fgauche;
            fgauche=reinterpret_cast<state::Field*>(elgauche);
                
            state::Field* fdroit;
            fdroit=reinterpret_cast<state::Field*>(eldroit);
            
            state::Field* fbas;
            fbas=reinterpret_cast<state::Field*>(elbas);
            
        
       
        
        if (el->getTypeID()==state::TypeID::FOWL){
            bla=reinterpret_cast<state::Fowl*>(el);
            if (fbas->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setY(bla->getY()+97);
                std::cout<<this->dx<<std::endl<<this->dy<<std::endl;
                this->dy=this->dy+1;
                s.setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s.getMobileElements();
                    s.notifyObservers(new state::StateEvent(state::StateEventID::FOWL_FALL),list);
                }
            }
            else{
            if (this->Direction==state::Direction::OUEST and fgauche->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setFowlStatus(state::FowlStatus::ALIVE_LEFT);
                s.setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s.getMobileElements();
                    s.notifyObservers(new state::StateEvent(state::StateEventID::FOWL_MOVE_LEFT),list);
                }
            }
            if (this->Direction==state::Direction::EST and fdroit->getFieldTypeID()==state::FieldTypeID::NEANT){
                bla->setFowlStatus(state::FowlStatus::ALIVE_RIGHT);
                s.setMobileElement(bla,this->idx);
                if (notify){
                    std::vector<state::Element*> list=s.getMobileElements();
                    s.notifyObservers(new state::StateEvent(state::StateEventID::FOWL_MOVE_RIGHT),list);
                }
            }
            }}
    }
}