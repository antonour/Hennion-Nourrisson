/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Render.hpp"
#include "../state.hpp"

using namespace state;

namespace Render{
    
    TileSet::~TileSet (){}
    
        //const char* getImageFile () const;
        //const Tile* getCharTile (char c) const;
    
    const Tile* TileSet::getFowlTile (const state::Fowl* fo) const{
        AnimatedTile* t = new AnimatedTile(0,0,0,0);
        //dimensions correspondantes à l'image chicken_large.png 
        if (fo->getFowlColor()==FowlColor::BLANK){
            t->x=0;
            t->y=0;
            t->width=48;
            t->height=48;
            
        }
        else if (fo->getFowlColor()==FowlColor::WHITE){
            
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=0;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=0;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=0;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=0;
            t->width=48;
            t->height=48;    
            }
            else{}
                
        }
        else if (fo->getFowlColor()==FowlColor::GREEN){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=48;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=48;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=48;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=48;
            t->width=48;
            t->height=48;    
            }
            else{}
        }
        else if (fo->getFowlColor()==FowlColor::BLACK){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=96;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=96;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=96;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=96;
            t->width=48;
            t->height=48;    
            }
        }
        else if (fo->getFowlColor()==FowlColor::BEIGE){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=144;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=144;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=144;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=144;
            t->width=48;
            t->height=48;    
            }
        }
        else if (fo->getFowlColor()==FowlColor::KHAKI){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=192;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=192;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=192;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=192;
            t->width=48;
            t->height=48;    
            }
        }
        else if (fo->getFowlColor()==FowlColor::BROWN){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=240;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=240;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=240;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=240;
            t->width=48;
            t->height=48;    
            }
        }
        else if (fo->getFowlColor()==FowlColor::GREY){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=288;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=288;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=288;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=288;
            t->width=48;
            t->height=48;    
            }
        }
        else if (fo->getFowlColor()==FowlColor::ORANGE){
            if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
            t->x=48;
            t->y=336;
            t->width=48;
            t->height=48;}
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
            t->x=144;
            t->y=336;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
            t->x=288;
            t->y=336;
            t->width=48;
            t->height=48;    
            }
            else if (fo->getFowlStatus()==FowlStatus::DEAD){
            t->x=384;
            t->y=336;
            t->width=48;
            t->height=48;    
            }
        }
        else{}
        
        return t;
    }
    
    //const Tile* getWeaponTile (const state::Weapon* w);
    
    //const Tile* getSpaceTile (const state::Space* s);
    
    const Tile* TileSet::getFieldTile (const state::Field* fi){
        StaticTile* t = new StaticTile(0,0,0,0);
        //dimensions correspondantes à l'image tileset.png
        switch (fi->getFieldTypeID()){
            
            case NEANT :
            {
                t->x=0;
                t->y=388;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGBROWN1 :
            {
                t->x=0;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGBROWN2 :
            {
                t->x=125;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
           
            case BIGBROWN3 :
            {
                t->x=250;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGBROWN4 :
            {
                t->x=0;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGBROWN5 :
            {
                t->x=125;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGBROWN6 :
            {
                t->x=250;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGSTONE1 :
            {
                t->x=0;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGSTONE2 :
            {
                t->x=125;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGSTONE3 :
            {
                t->x=250;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGSTONE4 :
            {
                t->x=0;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGSTONE5 :
            {
                t->x=150;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case BIGSTONE6 :
            {
                t->x=250;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLEBROWN1 :
            {
                t->x=375;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLEBROWN2 :
            {
                t->x=500;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLEBROWN3 :
            {
                t->x=375;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLEBROWN4 :
            {
                t->x=500;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLESTONE1 :
            {
                t->x=375;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLESTONE2 :
            {
                t->x=500;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLESTONE3 :
            {
                t->x=375;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case CIRCLESTONE4 :
            {
                t->x=500;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN1 :
            {
                t->x=625;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN2 :
            {
                t->x=750;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN3 :
            {
                t->x=875;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN4 :
            {
                t->x=1000;
                t->y=0;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN5 :
            {
                t->x=625;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN6 :
            {
                t->x=750;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN7 :
            {
                t->x=875;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLBROWN8 :
            {
                t->x=1000;
                t->y=97;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE1 :
            {
                t->x=625;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE2 :
            {
                t->x=750;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE3 :
            {
                t->x=875;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE4 :
            {
                t->x=1000;
                t->y=194;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE5 :
            {
                t->x=625;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE6 :
            {
                t->x=750;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE7 :
            {
                t->x=875;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }
            
            case SMALLSTONE8 :
            {
                t->x=1000;
                t->y=291;
                t->width=125;
                t->height=97;
                break;
            }      
                 
            default :
                break;
            
        }
        
        return t;
    }    
    
}