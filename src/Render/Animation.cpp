/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Animation.h"
#include <SFML/Graphics.hpp>

using namespace std;

namespace Render{
    
    Animation::Animation (AnimID id, sf::RenderWindow* window){
        this->animID=id;
        this->window=window;
    }
   
    void Animation::setDirection (state::Direction d){
        this->direction=d;        
    }
    
    void Animation::setSurface(Surface* su){
        this->surf= su;
    }
    
    AnimID Animation::getAnimID(){
        return this->animID;
    }
    
    state::Direction Animation::getDirection(){
        return this->direction;
    }
    
    void Animation::animate(int i, int j, int X, int Y){
        state::Direction d=this->getDirection();
        if (this->getAnimID()==AnimID::HIT){
                for(int k=1;k<250;k++){
                    if (k%5==0){
                        this->surf->rotateWeapon(i%40,j,X,Y,this->surf->weapontab[i],k/5,d);
                        this->update(0);
                    }
                }
            this->surf->dispWeapon(i%40,j,X,Y,this->surf->weapontab[i]);
        }
        if (this->getAnimID()==AnimID::JUMP && d==state::Direction::OUEST){
            for(int k=0;k<194;k++){
                if(k<=97){
                    this->surf->moveArrow((i-40)%40,(j-40)/40,X-(125*k)/194,Y-97-k/2,this->surf->arrowtab[i-40]);
                    this->surf->dispWeapon(i%40,j/40,X-(125*k)/194,Y-k/2,this->surf->weapontab[i]);
                    this->surf->moveFowl(i%40,j/40,X-(125*k)/194,Y-k/2,this->surf->fowltab[i]);
                    this->update(0);
                }
                else{
                    this->surf->moveArrow((i-40)%40,(j-40)/40,X-(125*k)/194,Y-194+k/2,this->surf->arrowtab[i-40]);
                    this->surf->dispWeapon(i%40,j/40,X-(125*k)/194,Y-97+k/2,this->surf->weapontab[i]);
                    this->surf->moveFowl(i%40,j/40,X-(125*k)/194,Y-97+k/2,this->surf->fowltab[i]);
                    this->update(0);
                }
            }
        }
        if (this->getAnimID()==AnimID::JUMP && d==state::Direction::EST){
            for(int k=0;k<194;k++){
                if(k<=97){
                    this->surf->moveArrow((i-40)%40,(j-40)/40,X+(125*k)/194,Y-97-k/2,this->surf->arrowtab[i-40]);
                    this->surf->dispWeapon(i%40,j/40,X+(125*k)/194,Y-k/2,this->surf->weapontab[i]);
                    this->surf->moveFowl(i%40,j/40,X+(125*k)/194,Y-k/2,this->surf->fowltab[i]);
                    this->update(0);
                }
                else{
                    this->surf->moveArrow((i-40)%40,(j-40)/40,X+(125*k)/194,Y-194+k/2,this->surf->arrowtab[i-40]);
                    this->surf->dispWeapon(i%40,j/40,X+(125*k)/194,Y-97+k/2,this->surf->weapontab[i]);
                    this->surf->moveFowl(i%40,j/40,X+(125*k)/194,Y-97+k/2,this->surf->fowltab[i]);
                    this->update(0);
                }
            }
        }
    }
    
    void Animation::sync (int64_t time){}
    
    void Animation::update (int64_t time){
        if (time==0){
            this->window->clear(sf::Color(102,102,225,255));
            this->window->draw(*surf);
            this->window->display();
        }
    }
    
}