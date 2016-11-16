/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <iostream>

namespace engine{
    
    Fire::Fire (int idx){
        this->idx=idx;
    }
    
    Fire::~Fire (){}
    
    void Fire::apply(state::State* s, bool notify){
         
    }
    
}