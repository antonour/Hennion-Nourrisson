/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"

namespace Render{
    
    StaticTile::StaticTile (int x, int y, int w, int h){
        this->x=x;
        this->y=y;
        this->width=w;
        this->height=h;
        
    }
    
    bool StaticTile::isAnimated () const{
        return false;
    }
    
    int StaticTile::getX (){
        return this->x;
    }
        
    int StaticTile::getY (){
        return this->y;
    }
    
    int StaticTile::getWidth (){
        return this->width;
    }
    
    int StaticTile::getHeight (){
        return this->height;
    }
    
    void StaticTile::setX (int x){
        this->x=x;
    }
    
    void StaticTile::setY (int y){
        this->y=y;
    }
    
    void StaticTile::setWidth (int w){
        this->width=w;
    }
    void StaticTile::setHeight (int h){
        this->height=h;
    }
    
}