/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include "../state.hpp"
#include <mutex>
#include <ctime>
#include <iostream>

using namespace sf;
using namespace std;

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
        std::lock_guard<std::mutex> lock(commands_mutex);
        this->waiting_commands->set(cmd);
    }
    
    void Engine::takeCommands (CommandSet* commands, CommandSet* commands1){
        this->currentCommands=commands;
        this->waiting_commands=commands1;
    }

    bool Engine::update (int64_t time){
        if (this->lastUpdateTime-time<=0){
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
    
    void Engine::runEngine(){
        Clock C;
        Time T;
        while(1){
            T=C.getElapsedTime();
            if (this->update(T.asMilliseconds())){            
                {
                    std::lock_guard<std::mutex> lock(commands_mutex);
                    swap(this->currentCommands,this->waiting_commands);
                    this->waiting_commands->commands.clear();
                }
                this->rules->takeCS(this->currentCommands);
                
                this->rules->apply();
                
                T=C.restart();
            }
        }
    }
}