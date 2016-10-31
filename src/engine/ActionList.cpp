/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"

namespace engine{
    
    /*ActionList::ActionList (state::State& s, bool notify){
        this->s=s;
        this->notify=notify;        
    }*/
    
    ActionList::~ActionList (){}
    
    int ActionList::size () const{
        return this->actions.size();
    }
    
    Action* ActionList::get (int i) const{
        return this->actions[i];
    }
    
    void ActionList::apply (){
        
    }
    
    void ActionList::add (Action* action){
        
    }
    
    void ActionList::addApply (Action* action){
        
    }
    
}