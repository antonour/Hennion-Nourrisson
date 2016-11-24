/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../ia.hpp"
#include "../state.hpp"
#include "../engine.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

namespace ia{
    TrueIA::TrueIA(state::State* currentState):AI(currentState){
        this->futureState=currentState;
    }
    
    engine::Command* TrueIA::run(state::State* s){
        
    }
    
    int TrueIA::findHole(int X, int Y, int& DX){
        bool found=false;
        int nbrepas=0;
        int compteurgauche=15000;
        int compteurdroite=15000;
        for (int idx=(X/125+(Y/97)*40);idx>((Y/97)*40)-1;idx--){
            state::Element * elterr= this->currentState->getStaticElement(idx);
            state::Field* terr=reinterpret_cast<state::Field*>(elterr);
            if (terr->getFieldTypeID()==state::FieldTypeID::NEANT && found==false){
                state::Element * sol= this->currentState->getStaticElement(idx+40);
                terr=reinterpret_cast<state::Field*>(sol);
                if (terr->getFieldTypeID()==state::FieldTypeID::NEANT){
                    found=true;
                    compteurgauche=X-terr->getX();
                }
            }
        }
        found=false;
        for (int idx=(X/125+(Y/97)*40);idx<(39+(Y/97)*40)+1;idx++){
            state:: Element * elterr= this->currentState->getStaticElement(idx);
            state::Field* terr=reinterpret_cast<state::Field*>(elterr);
            if (terr->getFieldTypeID()==state::FieldTypeID::NEANT && found==false){
                state::Element * sol= this->currentState->getStaticElement(idx+40);
                terr=reinterpret_cast<state::Field*>(sol);
                if (terr->getFieldTypeID()==state::FieldTypeID::NEANT){
                    found=true;
                    compteurdroite=terr->getX()-X;
                }
            }
        }
        found=false;
        if (compteurgauche<=compteurdroite){
            DX=X-compteurgauche;
            nbrepas=compteurgauche/2;
        }
        else{
            DX=X+compteurdroite;
            nbrepas=compteurdroite/2;
        }
        return nbrepas;
    }
    
    void TrueIA::findLanding(int X, int Y, int& DY){
        for (int idx=(X/125+(Y/97)*40);idx<(X/125+29*40)+1;idx+=40){
            state::Element * elterr= this->currentState->getStaticElement(idx);
            state::Field* terr=reinterpret_cast<state::Field*>(elterr);
            if (terr->getFieldTypeID()!=state::FieldTypeID::NEANT){
                DY=terr->getY()-97;
                return;
            }
        }
    }
    
    int TrueIA::findNearestWay(){
        int index=this->currentState->getSelected();
        state::Element* el= this->currentState->getMobileElement(index);
        state::Fowl* fowl=reinterpret_cast<state::Fowl*>(el);
        state::FowlColor col=fowl->getFowlColor();
        bool obstacle=false;
        int X=fowl->getX();
        int Y=fowl->getY();
        int nbrepas=0;
        int min=1500;
        state:: Field* terr;
        
        for (state::Element* e: this->currentState->getMobileElements()){
            obstacle=false;
            state::Fowl* f=reinterpret_cast<state::Fowl*>(e);
            if (f->getY()>=Y && f->isSelected()==false && f->getFowlColor()!=state::FowlColor::BLANK && f->getFowlColor()!=col){
                if (f->getY()==Y && f->getX()>X){
                    for (int idx=(X/125+(Y/97)*40);idx<(f->getX()/125+(Y/97)*40)+1;idx++){
                        state::Element * elterr= this->currentState->getStaticElement(idx);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()!=state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                        elterr= this->currentState->getStaticElement(idx+40);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()==state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                    }
                    if (obstacle){
                        nbrepas=15000;
                    }
                    else {
                        nbrepas=(f->getX()-X)/2 - 40;
                    }
                }
                if (f->getY()==Y && f->getX()<X){
                    for (int idx=(X/125+(Y/97)*40);idx>(f->getX()/125+(Y/97)*40)-1;idx--){
                        state::Element * elterr= this->currentState->getStaticElement(idx);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()!=state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                        elterr= this->currentState->getStaticElement(idx+40);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()==state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                    }
                    if (obstacle){
                        nbrepas=15000;
                    }
                    else {
                        nbrepas=(X-f->getX())/2 - 40;
                    }
                }
                if (f->getY()==Y && f->getX()==X){
                    nbrepas=0;
                }
                if (f->getY()>Y){
                    int DX=X;
                    int DY=Y;
                    int DDX=X;
                    int DDY=Y;
                    nbrepas=this->findHole(X,Y,DX);
                    this->findLanding(DX,Y,DY);
                    while (DY<f->getY()){
                        DDX=DX;
                        DDY=DY;
                        nbrepas+=this->findHole(DDX,DDY,DX);
                        this->findLanding(DDX,DDY,DY);
                    }
                    if (DY>f->getY()){
                        nbrepas=15000;
                    }
                }
                if (nbrepas<min){
                    min=nbrepas;
                }
            }
        }
    return min;
    }
}
