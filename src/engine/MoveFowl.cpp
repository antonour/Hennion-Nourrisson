/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

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
    
    void MoveFowl::setOrientation (state::Direction orientation){
        this->Orientation=orientation;
    }
    
    void MoveFowl::setDirection (state::Direction direction){
        this->Direction=direction;
        this->poule->setDirection(direction);
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
   
}