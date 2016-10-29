/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"
#include "../state.hpp"
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
    }
    
    void Layer::stateChanged (state::StateEvent* e, std::vector<state::Element*>& list){
        if (e->getStateEventID()==state::StateEventID::FILECHAR_LOADED){
            vector<int> tab;
            surface->generateMap(list, tab);
            if (!surface->load("../res/chicken_large.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), &tab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }
        }
        if (e->getStateEventID()==state::StateEventID::FILEMAP_LOADED){
            vector<int> tab2;
            surface->generateMap(list, tab2);
            if (!surface->load("../res/tileset.png", sf::Vector2u(125, 97),sf::Vector2u(125,97), &tab2[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }   
        }
    }
    
}