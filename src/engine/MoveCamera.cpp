/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../engine.hpp"
#include <SFML/Graphics.hpp>

namespace engine{
    
    MoveCamera::MoveCamera (){
        dxCenter=2500;
        dyCenter=1300;
        dzoom=3.f;
        view.setCenter(this->dxCenter,this->dyCenter);
        view.zoom(this->dzoom);        
    }
    
    MoveCamera::~MoveCamera (){}
    
    void MoveCamera::ZoomIn (){
        if (dzoom>0.5){
        dzoom=this->dzoom*0.9f;
        view.zoom(0.9f);}
    }
    
    void MoveCamera::ZoomOut (){
        if (dzoom<5.){
        this->dzoom=this->dzoom*1.1f;
        view.zoom(1.1f);}
    }
    
    void MoveCamera::MoveOnLeft (){
        if (dxCenter>=0){
        dxCenter=dxCenter-75;
        view.setCenter(dxCenter,dyCenter);}
    }
    
    void MoveCamera::MoveOnRight (){
        if (dxCenter<=4949){
        dxCenter=dxCenter+75;
        view.setCenter(dxCenter,dyCenter);}
    }
    
    void MoveCamera::MoveOnUp (){
        if (dyCenter>=0){
        dyCenter=dyCenter-75;
        view.setCenter(dxCenter,dyCenter);}
    }
    
    void MoveCamera::MoveOnDown (){
        if (dyCenter<=2625){
        dyCenter=dyCenter+75;
        view.setCenter(dxCenter,dyCenter);}
    }
    
    sf::View MoveCamera::getView (){
        return view;
    }
    
}
