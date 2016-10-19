/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"

namespace Render{
    
    Tile::Tile (int x, int y, int w, int h){
        this->x=x;
        this->y=y;
        this->width=w;
        this->height=h;
    }
    
    Tile::~Tile (){}
    
        
    int Tile::getX (){
        return this->x;
    }
    
    int Tile::getY (){
        return this->y;
    }
    
    int Tile::getWidth () const{
        return this->width;
    }
    
    int Tile::getHeight () const{
        return this->height;
    }
    
    void Tile::setX (int x){
        this->x=x;
    }
    
    void Tile::setY (int y){
        this->y=y;
    }
    
    void Tile::setWidth (int const w){
        this->width=w;
    }
    
    void Tile::setHeight (int const h){
        this->height=height;
    }
    
}