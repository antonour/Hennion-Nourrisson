/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"

namespace Render{
    
    AnimatedTile::AnimatedTile (int x, int y, int w, int h){
        this->x=x;
        this->y=y;
        this->width=w;
        this->height=h;
    }
    
    AnimatedTile::~AnimatedTile (){}
    
    bool AnimatedTile::isAnimated () const{
        return true;
    }
    
    int AnimatedTile::getX (){
        return this->x;
    }
        
    int AnimatedTile::getY (){
        return this->y;
    }
    
    int AnimatedTile::getWidth (){
        return this->width;
    }
    
    int AnimatedTile::getHeight (){
        return this->height;
    }
    
    void AnimatedTile::setX (int x){
        this->x=x;
    }
    
    void AnimatedTile::setY (int y){
        this->y=y;
    }
    
    void AnimatedTile::setWidth (int w){
        this->width=w;
    }
    void AnimatedTile::setHeight (int h){
        this->height=h;
    }
    
}