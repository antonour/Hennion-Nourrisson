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
            surface->generateMap(list, surface->fowltab);
            if (!surface->load("../res/chicken_large.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), &surface->fowltab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }
        }
        if (e->getStateEventID()==state::StateEventID::FILEMAP_LOADED){
            surface->generateMap(list, surface->fieldtab);
            if (!surface->load("../res/tileset.png", sf::Vector2u(125, 97),sf::Vector2u(125,97), &surface->fieldtab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }   
        }
        if (e->getStateEventID()==state::StateEventID::FOWL_DEAD){
            for(int i=0; i<(int)surface->fowltab.size();i++){
                if (surface->fowltab[i]%9==1){
                    surface->fowltab[i]+=7;
                }
                if (surface->fowltab[i]%9==3){
                    surface->fowltab[i]+=5;
                }
                if (surface->fowltab[i]%9==6){
                    surface->fowltab[i]+=2;
                }
            }
            if (!surface->load("../res/chicken_large.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), &surface->fowltab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }   
        }
        if (e->getStateEventID()==state::StateEventID::FOWL_MOVE){
            int i=0;
            for (state::Element* pers: list){
                if (pers->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* poule;
                    poule=reinterpret_cast<state::Fowl*>(pers);
                    if (poule->getFowlStatus()==state::FowlStatus::ALIVE_LEFT){
                       
                       if (surface->fowltab[i]%9==1){
                           surface->fowltab[i]+=1;
                       }
                       else if (surface->fowltab[i]%9==2){
                           surface->fowltab[i]+=1;
                       }
                       else if (surface->fowltab[i]%9==3){
                           surface->fowltab[i]+=1;
                       }
                       else if (surface->fowltab[i]%9==4){
                           surface->fowltab[i]-=2;
                       }
                       else
                           surface->fowltab[i]=surface->fowltab[i]-surface->fowltab[i]%9+1;
                    }
                    if (poule->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT){
                       
                       if (surface->fowltab[i]%9==1){
                           surface->fowltab[i]+=4;
                       }
                       else if (surface->fowltab[i]%9==5){
                           surface->fowltab[i]+=1;
                       }
                       else if (surface->fowltab[i]%9==6){
                           surface->fowltab[i]+=1;
                       }
                       else if (surface->fowltab[i]%9==7){
                           surface->fowltab[i]-=2;
                       }
                       else
                           surface->fowltab[i]=surface->fowltab[i]-surface->fowltab[i]%9+1;
                    }
                }
                i++;
            }
            if (!surface->load("../res/chicken_large.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), &surface->fowltab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }   
            
        }
    }
    
    void Layer::sync (int64_t time){}
    
    void Layer::update (int64_t time){}
    
}