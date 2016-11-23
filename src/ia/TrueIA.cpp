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
    
    int TrueIA::findHole(int X, int Y, int& DX, int& DY){
        bool found=false;
        int nbrepas=0;
        int compteurgauche=15000;
        int compteurdroite=15000;
        for (int idx=(X/125+(Y/97)*40);idx>((Y/97)*40-1)+1;idx--){
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
        for (int idx=(X/125+(Y/97)*40);idx<(39+(Y/97)*40+1)+1;idx++){
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
        for (int idx=(DX/125+(DY/97)*40);idx<DX/125+1160+1;idx+=40){
            state::Element * air= this->currentState->getStaticElement(idx);
            state::Field* terr=reinterpret_cast<state::Field*>(air);
            if (terr->getFieldTypeID()!=state::FieldTypeID::NEANT && found==false){
                found=true;
                DY=terr->getY();
            }                    
        }
        return nbrepas;
    }
    
    int TrueIA::findNearestWay(){
        int index=this->currentState->getSelected();
        state::Element* el= this->currentState->getMobileElement(index);
        state::Fowl* fowl=reinterpret_cast<state::Fowl*>(el);
        bool obstacle=false;
        int X=fowl->getX();
        int Y=fowl->getY();
        int nbrepas=0;
        int min=1500;
        state:: Field* terr;
        
        for (state::Element* e: this->currentState->getMobileElements()){
            obstacle=false;
            state::Fowl* f=reinterpret_cast<state::Fowl*>(e);
            if (f->getY()>=Y){
                if (f->getY()==Y && f->getX()>X){
                    for (int idx=(X/125+(Y/97)*40);idx<(f->getX()/125+(f->getY()/97)*40)+1;idx++){
                        state::Element * elterr= this->currentState->getStaticElement(idx);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()==state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                        elterr= this->currentState->getStaticElement(idx+40);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()!=state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                    }
                    if (obstacle){
                        nbrepas=15000;
                    }
                    else {
                        nbrepas=(f->getX()-X)/2;
                    }
                }
                if (f->getY()==Y && f->getX()<X){
                    for (int idx=(X/125+(Y/97)*40);idx>(f->getX()/125+(f->getY()/97)*40)-1;idx--){
                        state::Element * elterr= this->currentState->getStaticElement(idx);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()==state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                        elterr= this->currentState->getStaticElement(idx+40);
                        terr=reinterpret_cast<state::Field*>(elterr);
                        if (terr->getFieldTypeID()!=state::FieldTypeID::NEANT){
                            obstacle=true;
                        }
                    }
                    if (obstacle){
                        nbrepas=15000;
                    }
                    else {
                        nbrepas=(X-f->getX())/2;
                    }
                }
                if (f->getY()==Y && f->getX()==X){
                    nbrepas=0;
                }
                if (f->getY()>Y){
                    int DX;
                    DX=f->getX();
                    int DY;
                    DY=f->getY();
                    cout << DY << endl;
                    while (DY!=Y){
                        nbrepas+=this->findHole(X,Y,DX,DY);
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
