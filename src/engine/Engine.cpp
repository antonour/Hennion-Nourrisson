/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <mutex>

namespace engine{
    
    Engine::Engine (){
        this->lastUpdateTime=150;
    }
    
    Engine::~Engine (){}
    
    state::State* Engine::getState (){
        return this->currentState;
    }
    
    void Engine::setState(state::State* s){
        this->currentState=s;
    }
    
    void Engine::setRuler(Ruler* r){
        this->rules=r;
    }
    
    void Engine::addCommand (Command* cmd){
        this->currentCommands->set(cmd);
    }
    
    void Engine::takeCommands (CommandSet* commands){
        this->currentCommands=commands;
    }

    bool Engine::update (int64_t time, int64_t* next_time){
        if (this->lastUpdateTime-time<=0){
            this->rules->apply();
            return true;
        }
        else{
            return false;
        }
    }
    
    void Engine::loadlevel (){
        this->currentState->loadChar("./src/fichierperso.txt");
        this->currentState->loadLevel("./src/fichiermap.txt");
    }
    
}