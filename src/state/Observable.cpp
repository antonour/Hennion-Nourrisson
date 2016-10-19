/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"../state.hpp"
#include"../Render.hpp"

namespace state{
    Observable::~Observable(){}
    
    void Observable::registerObserver(IObserver* observer){
        observers.push_back(observer);
    }

    
    void Observable::notifyObservers(const StateEvent& e){
        for(auto observer:observers){
            observer->stateChanged(e);
        }
    }
}
