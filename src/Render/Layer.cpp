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
            if (!surface->loadChar("../res/chicken_large.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), &surface->fowltab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER CHICKEN");
            }
            if (!surface->loadArrow("../res/arrow.png", sf::Vector2u(125, 97),sf::Vector2u(48,48), &surface->arrowtab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER ARROW");
            }
        }
        
        if (e->getStateEventID()==state::StateEventID::FILEMAP_LOADED){
            surface->generateMap(list, surface->fieldtab);
            if (!surface->loadMap("../res/tileset.png", sf::Vector2u(125, 97),sf::Vector2u(125,97), &surface->fieldtab[0], 40, 30)){
                throw std::runtime_error("IMPOSSIBLE DE CHARGER LE FICHIER");
            }   
        }
        
        if (e->getStateEventID()==state::StateEventID::FOWL_SELECTED){
            int i=0,X=0,Y=0;
            for (state::Element* pers: list){
                if (pers->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* poule;
                    poule=reinterpret_cast<state::Fowl*>(pers);
                    if (poule->getFowlStatus()==state::FowlStatus::ALIVE_FACE && poule->isSelected()){
                       X=poule->getX();
                       Y=poule->getY();
                       surface->arrowtab[i-40]=0;
                       surface->moveArrow((i-40)%40,(i-40)/40,X,Y-97,surface->arrowtab[i-40]);
                    }
                }
                i++;
            }
        
        }
        
        if (e->getStateEventID()==state::StateEventID::FOWL_DEAD){
            int i=0;
            int X=0,Y=0;
            for(state::Element* el:list){
                if (el->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* poulet;
                    poulet=reinterpret_cast<state::Fowl*>(el);
                    if (poulet->getFowlStatus()==state::FowlStatus::DEAD && poulet->isSelected()){
                        X=poulet->getX();
                        Y=poulet->getY();
                        surface->arrowtab[i-40]=0;
                        if (surface->fowltab[i]%9==1){
                            surface->fowltab[i]+=7;
                        }
                        if (surface->fowltab[i]%9==2){
                            surface->fowltab[i]+=6;
                        }
                        if (surface->fowltab[i]%9==3){
                            surface->fowltab[i]+=5;
                        }
                        if (surface->fowltab[i]%9==4){
                            surface->fowltab[i]+=4;
                        }
                        if (surface->fowltab[i]%9==5){
                            surface->fowltab[i]+=3;
                        }
                        if (surface->fowltab[i]%9==6){
                            surface->fowltab[i]+=2;
                        }
                        if (surface->fowltab[i]%9==7){
                            surface->fowltab[i]+=1;
                        }
                
                        surface->kill(i%40,i/40,surface->fowltab[i]);
                        surface->moveArrow((i-40)%40,(i-40)/40,X,Y-97,surface->arrowtab[i-40]);
                    }
                }
                i++;
            }
        }
        if (e->getStateEventID()==state::StateEventID::FOWL_MOVE_RIGHT){
            int i=0;
            int X=0,Y=0;
            for (state::Element* pers: list){
                if (pers->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* poule;
                    poule=reinterpret_cast<state::Fowl*>(pers);
                    if (poule->getFowlStatus()==state::FowlStatus::ALIVE_RIGHT && poule->isSelected()){
                       X=poule->getX();
                       Y=poule->getY();
                       X+=5;
                       poule->setX(X);
                       surface->arrowtab[i-40]=0;
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
                       surface->moveFowl(i%40,i/40,X,Y,surface->fowltab[i]);
                       surface->moveArrow((i-40)%40,(i-40)/40,X,Y-97,surface->arrowtab[i-40]);
                    }
                    
                }
                i++;
            }
        }
        if (e->getStateEventID()==state::StateEventID::FOWL_MOVE_LEFT){
            int i=0;
            int X=0,Y=0;
            for (state::Element* pers: list){
                if (pers->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* poule;
                    poule=reinterpret_cast<state::Fowl*>(pers);
                    if (poule->getFowlStatus()==state::FowlStatus::ALIVE_LEFT && poule->isSelected()){
                       X=poule->getX();
                       Y=poule->getY();
                       X-=5;
                       poule->setX(X);
                       surface->arrowtab[i-40]=0;
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
                       surface->moveFowl(i%40,i/40,X,Y,surface->fowltab[i]);
                       surface->moveArrow((i-40)%40,(i-40)/40,X,Y-97,surface->arrowtab[i-40]);
                    }
                }
                i++;
            }
        }
        
        if (e->getStateEventID()==state::StateEventID::FOWL_STOP){
            int i=0;
            int X=0;
            int Y=0;
            for (state::Element* pers: list){
                if (pers->getTypeID()==state::TypeID::FOWL){
                    state::Fowl* poule;
                    poule=reinterpret_cast<state::Fowl*>(pers);
                    if (poule->getFowlStatus()==state::FowlStatus::ALIVE_FACE && poule->isSelected()==false){
                       X=poule->getX();
                       Y=poule->getY();
                       surface->arrowtab[i-40]=1;
                       if (surface->fowltab[i]%9==2){
                           surface->fowltab[i]-=1;
                       }
                       else if (surface->fowltab[i]%9==3){
                           surface->fowltab[i]-=2;
                       }
                       else if (surface->fowltab[i]%9==4){
                           surface->fowltab[i]-=3;
                       }
                       else if (surface->fowltab[i]%9==5){
                           surface->fowltab[i]-=4;
                       }
                       else if (surface->fowltab[i]%9==6){
                           surface->fowltab[i]-=5;
                       }
                       else if (surface->fowltab[i]%9==7){
                           surface->fowltab[i]-=6;
                       }
                       surface->moveFowl(i%40,i/40,X,Y,surface->fowltab[i]);
                       surface->moveArrow((i-40)%40,(i-40)/40,X,Y-97,surface->arrowtab[i-40]);
                    }
                }
                i++;
            }
        }
    }
    
    void Layer::sync (int64_t time){}
    
    void Layer::update (int64_t time){}
    
}