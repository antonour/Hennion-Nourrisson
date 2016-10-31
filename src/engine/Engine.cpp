/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <mutex>

namespace engine{
    
    Engine::Engine (){}
    
    Engine::~Engine (){}
    
    EngineMode Engine::getMode () const{
        return this->mode;
    }
    
    const state::State& Engine::getState () const{
        return this->currentState;
    }
    
    void Engine::addCommand (Command* cmd){
        
    }
    
    void Engine::takeCommands (CommandSet& commands){
        
    }
    
    /*std::mutex& Engine::getUpdateMutex () const{
        return &this->update_mutex;
    }*/
    
    bool Engine::update (int64_t time, int64_t* next_time){
        return false;
    }
  
    void Engine::setMode (EngineMode mode){
        this->mode=mode;
    }
    
    void Engine::loadlevel (const char* file_name){}
    
}