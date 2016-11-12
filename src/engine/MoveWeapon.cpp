/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    MoveWeapon::MoveWeapon (int idx){
        this->idx=idx;
    }
    
    MoveWeapon::~MoveWeapon (){}
    
    void MoveWeapon::setCoords (int dx, int dy, int dpos){
        this->dx=dx;
        this->dy=dy;
        this->dpos=dpos;
    }
    
    void MoveWeapon::setOrientation (state::Orientation orientation){
        this->Orientation=orientation;
    }
    
    void MoveWeapon::apply(state::State* s, bool notify){}
     
    
}