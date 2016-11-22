/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../ia.hpp"
#include "../state.hpp"
#include "../engine.hpp"
#include <stdlib.h>

using namespace std;

namespace ia{
    AI::AI(state::State* currentState){
        this->currentState=currentState;
    }
    
    AI::~AI(){}
}
