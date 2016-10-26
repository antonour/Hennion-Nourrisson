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
    
    const Tile* const getElementTile (state::Element* e){
        
        if (e->isStatic()){
            StaticTile* t1 = new StaticTile(0,0,0,0);
            StaticElement* e1;
            e1 = reinterpret_cast<StaticElement*>(e);
            if (e1->isSpace()){//si c'est un space
                      
            }
            
            else{
            //dimensions correspondantes à l'image tileset.png
                Field* fi;
                fi = reinterpret_cast<Field*>(e1);
                if(fi->getFieldTypeID()==FieldTypeID::NEANT){
                        t1->x=0;
                        t1->y=388;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGBROWN1){
                        t1->x=0;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGBROWN2){
                        t1->x=125;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGBROWN3){
                        t1->x=250;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGBROWN4){
                        t1->x=0;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGBROWN5){
                        t1->x=125;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGBROWN6){
                        t1->x=250;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGSTONE1){
                        t1->x=0;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGSTONE2){
                        t1->x=125;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGSTONE3){
                        t1->x=250;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGSTONE4){
                        t1->x=0;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGSTONE5){
                        t1->x=150;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::BIGSTONE6){
                        t1->x=250;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLEBROWN1){
                        t1->x=375;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLEBROWN2){
                        t1->x=500;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLEBROWN3){
                        t1->x=375;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLEBROWN4){
                        t1->x=500;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLESTONE1){
                        t1->x=375;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLESTONE2){
                        t1->x=500;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLESTONE3){
                        t1->x=375;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::CIRCLESTONE4){
                        t1->x=500;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN1){
                        t1->x=625;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN2){
                        t1->x=750;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN3){
                        t1->x=875;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN4){
                        t1->x=1000;
                        t1->y=0;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN5){
                        t1->x=625;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN6){
                        t1->x=750;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN7){
                        t1->x=875;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLBROWN8){
                        t1->x=1000;
                        t1->y=97;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE1){
                        t1->x=625;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE2){
                        t1->x=750;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE3){
                        t1->x=875;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE4){
                        t1->x=1000;
                        t1->y=194;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE5){
                        t1->x=625;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE6){
                        t1->x=750;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE7){
                        t1->x=875;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }
                else if (fi->getFieldTypeID()==FieldTypeID::SMALLSTONE8){
                        t1->x=1000;
                        t1->y=291;
                        t1->width=125;
                        t1->height=97;
                    }      
                else{}
                
        }
        return t1;
        }
        
        else{
            AnimatedTile* t2 = new AnimatedTile(0,0,0,0);
            MobileElement* e2;
            e2 = reinterpret_cast<MobileElement*>(e);
            if (e2->isFowl()){
            //dimensions correspondantes à l'image chicken_large.png
            Fowl* fo;
            fo = reinterpret_cast<Fowl*>(e2);
                if (fo->getFowlColor()==FowlColor::BLANK){
                    t2->x=0;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;

                }
                else if (fo->getFowlColor()==FowlColor::WHITE){

                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=0;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else{}

                }
                else if (fo->getFowlColor()==FowlColor::GREEN){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=48;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else{}
                }
                else if (fo->getFowlColor()==FowlColor::BLACK){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=96;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==FowlColor::BEIGE){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=144;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==FowlColor::KHAKI){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=192;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==FowlColor::BROWN){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=240;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==FowlColor::GREY){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=288;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else if (fo->getFowlColor()==FowlColor::ORANGE){
                    if (fo->getFowlStatus()==FowlStatus::ALIVE_FACE){
                    t2->x=48;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;}
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    t2->x=144;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT){
                    t2->x=288;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;    
                    }
                    else if (fo->getFowlStatus()==FowlStatus::DEAD){
                    t2->x=384;
                    t2->y=336;
                    t2->width=48;
                    t2->height=48;    
                    }
                }
                else{}}
            else{//si c'est une arme
            }
                
            
            return t2;
            }

        }

}