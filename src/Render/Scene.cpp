/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"

namespace Render{
    
    Scene::Scene (){}
    Scene::~Scene (){}
    
    int Scene::getWidth () const{
        return this->Width;
    }
    
    int Scene::getHeight () const{
        return this->Height;
    }
    
    int Scene::getLayerCount () const{
        int Count=0;
        return Count;
    }
    
    void Scene::setLayer (int idx, Layer* layer){
        
    }
        
    void Scene::registerObservers (const state::State* s){
        
    }
    
    void Scene::unregisterObservers (const state::State* s){
        
    }
    
    void Scene::stateChanged (state::StateEvent* e){
        
    }
    
    void Scene::stateChanged (state::StateEvent* e, std::vector<state::Element*>& list){
        
    }
    
    void Scene::sync (int64_t time){}
    
    void Scene::update (int64_t time){}
    
}