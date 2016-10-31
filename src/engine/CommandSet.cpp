/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <map>

namespace engine{
    
    CommandSet::~CommandSet (){}
    
    int  CommandSet::size () const{
        return 0;
    }
    
    Command* CommandSet::get (int category){
        return this->commands[category];
    }
    
    void CommandSet::set (Command* cmd){
    }
    
    void CommandSet::take (CommandSet& commands, bool replace){}
    
}