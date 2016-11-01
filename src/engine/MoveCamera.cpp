/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include <SFML/Graphics.hpp>

namespace engine{
    
    MoveCamera::MoveCamera (){
        dxCenter=3000;
        dyCenter=3000;
        dzoom=6.f;
        view.setCenter(this->dxCenter,this->dyCenter);
        view.zoom(this->dzoom);        
    }
    
    MoveCamera::~MoveCamera (){}
    
    void MoveCamera::ZoomIn (){
        dzoom=this->dzoom*0.9f;
        view.zoom(0.9f);
    }
    
    void MoveCamera::ZoomOut (){
        this->dzoom=this->dzoom*1.1f;
        view.zoom(1.1f);
    }
    
    void MoveCamera::MoveOnLeft (){
        
        dxCenter=dxCenter-75;
        view.setCenter(dxCenter,dyCenter);
    }
    
    void MoveCamera::MoveOnRight (){
        dxCenter=dxCenter+75;
        view.setCenter(dxCenter,dyCenter);
    }
    
    void MoveCamera::MoveOnUp (){
        dyCenter=dyCenter-75;
        view.setCenter(dxCenter,dyCenter);
    }
    
    void MoveCamera::MoveOnDown (){
        dyCenter=dyCenter+75;
        view.setCenter(dxCenter,dyCenter);
    }
    
    sf::View MoveCamera::getView (){
        return view;
    }
    
}
