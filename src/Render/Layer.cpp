/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"
#include "state/StateEvent.h"
#include <iostream>

using namespace std;

namespace Render{
    
    Layer::Layer (){}
    
    Layer::~Layer (){}
    
    const TileSet* Layer::getTileSet (){
        return this->tileset;
    }
    
    void Layer::setTileSet (const TileSet* tileset){
        this->tileset=tileset;
    }
    
    void Layer::setSurface (Surface* surface){
        this->surface=surface;
    }
    
    void Layer::setAnimation (int i, Animation* a){
        
    }
    
    void Layer::printText (int x, int y, const char* msg, int spriteIdx, int w, int h){
        
    }
    
    void Layer::update (const state::State& elementList){
    }
    
    void Layer::stateChanged (state::StateEvent* e){
        cout << "NOTIFIE" << endl;
    }
    
}