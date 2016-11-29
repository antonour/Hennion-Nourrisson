/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <map>

namespace engine{
    
    CommandSet::CommandSet (){}
    
    CommandSet::~CommandSet (){}
    
    Command* CommandSet::get (int idx){
        return this->commands[idx];
    }
    
    void CommandSet::set (Command* cmd){
        this->commands.push_back(cmd);
    }
    
    void CommandSet::take (CommandSet& commands, bool replace){
        if (replace==true){
 //           Engine::takeCommands(commands);
        }
    }
    
}