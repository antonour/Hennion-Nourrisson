/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    ChooseWeapon::ChooseWeapon (int idx){
        this->idx=idx;
    }
    
    ChooseWeapon::~ChooseWeapon (){}
    
    void ChooseWeapon::apply(state::State* s, bool notify){}

    
    
}