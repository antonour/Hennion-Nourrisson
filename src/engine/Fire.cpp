/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    Fire::Fire (state::Orientation orientation, int puissance){
        this->orientation=orientation;
        this->puissance=puissance;
    }
    
    Fire::~Fire (){}
    
    void Fire::apply(state::State* s, bool notify){}

    
 
    
}