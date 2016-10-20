/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Animation.h"

namespace Render{
    
    Animation::Animation (int i, int x, int y, const Tile* a){
        this->i=i;
        this->x=x;
        this->y=y;
        this->tile=a;
    }
    
    void Animation::setDirection (state::Direction d){
        this->direction=d;        
    }
    
    void Animation::setSpeed (float speed){
        this->speed=speed;
    }
    
}