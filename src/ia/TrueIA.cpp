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
        int m = getMin();
        int idx=s->getSelected();
        //cout<<m<<".."<<idx<<".."<<this->ite1<<".."<<this->min<<endl;
        
        state::Element* e = s->getMobileElement(s->getSelected());
        int X=e->getX();
        int Y=e->getY();
        state::Element* bg=s->getStaticElement(X/125+(Y/97)*40-1);
        state::Element* bd=s->getStaticElement(X/125+(Y/97)*40+1);
        state::Fowl* f = reinterpret_cast<state::Fowl*>(e);
        state::Field* blocgauche=reinterpret_cast<state::Field*>(bg);
        state::Field* blocdroite=reinterpret_cast<state::Field*>(bd);
        if (f->getMU()==300){
            this->ite1=0;
            this->ite2=0;
            this->ite3=0;            
        }      
        
        
        //Premier Déplacement aléatoire
            if (this->ite1==0){
                this->min=m;
                srand(time(NULL));
                int r=rand()%2 + 1;
                this->ite2=1;
                
                if ((r==1 && blocgauche->getFieldTypeID()==state::FieldTypeID::NEANT) || blocdroite->getFieldTypeID()!=state::FieldTypeID::NEANT){
                    this->ite1=1;
                    this->ite3=1;
                    return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
                }
                else{
                    this->ite1=2;
                    this->ite3=2;
                    return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
                }
            }
        
        //On corrige si le 1er Deplacement était mauvais
            if (this->min<m){
                
                if ((this->ite1==1 && blocdroite->getFieldTypeID()==state::FieldTypeID::NEANT) || blocgauche->getFieldTypeID()!=state::FieldTypeID::NEANT){
                    this->ite3=2;
                    return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);           
                }
                else{
                    this->ite3=1;
                    return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
                } 
            }
        
        //Si la cible est à portée
        
        if (m>0 and m<295){
            
            if ((this->ite3==1  && blocgauche->getFieldTypeID()==state::FieldTypeID::NEANT) || blocdroite->getFieldTypeID()!=state::FieldTypeID::NEANT){
                return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
            }
            else{
                return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
            }
        }
        else if (m>305){
            if ((this->ite3==1  && blocgauche->getFieldTypeID()==state::FieldTypeID::NEANT) || blocdroite->getFieldTypeID()!=state::FieldTypeID::NEANT){
                return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::OUEST);
            }
            else{
                return new engine::MoveCommand(0,0,engine::MoveID::CHICKEN_WALK,idx,state::Direction::EST);
            }
        }
        else{
            
            if (this->ite3==1){
                return new engine::FireCommand(this->currentState->getSelected(),state::Direction::OUEST);
            }
            else{
                return new engine::FireCommand(this->currentState->getSelected(),state::Direction::EST);
            }            
        }
        
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
            if (f->getY()>=Y && f->isSelected()==false && f->getFowlColor()!=state::FowlColor::BLANK && f->getFowlColor()!=col && f->getFowlStatus()!=state::FowlStatus::DEAD){
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
                    if (DY==f->getY()){
                        if (DX<f->getX()){
                            for (int idx=(DX/125+(DY/97)*40);idx<(f->getX()/125+(DY/97)*40)+1;idx++){
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
                                nbrepas+=(f->getX()-DX)/2 - 40;
                            }
                        }
                        if (DX>f->getX()){
                            for (int idx=(DX/125+(DY/97)*40);idx>(f->getX()/125+(DY/97)*40)-1;idx--){
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
                                nbrepas+=(DX-f->getX())/2 - 40;
                            }
                        }
                    }
                }
                if (nbrepas<min){
                    min=nbrepas;
                }
            }
        }
    return min;
    }

    int TrueIA::getMin (){
        
        int idx1,idx2,idx3,idx4;
        int min1,min2,min3,min4;
        min1 = 500000;
        min2 = 500000;
        min3 = 500000;
        min4 = 500000;
        idx1 = 0;
        idx2 = 0;
        idx3 = 0;
        idx4 = 0;
        int mini = 0;
        int idx = 0;
        
        if (this->ite2==0){
        
            idx1 = this->currentState->getSelected();
            min1 = findNearestWay();
        
            mini = min1;
            idx = idx1;
        
            engine::SelectFowl* Sel = new engine::SelectFowl(idx1,false);
            Sel->apply(this->currentState,false);
                
            idx2 = this->currentState->getSelected();
        
            if (idx2!=idx1){
                min2 = findNearestWay();  
        
                Sel->apply(this->currentState,false);
        
                idx3 = this->currentState->getSelected();
        
                if (idx3!=idx1){
                    min3 = findNearestWay();
                
                    idx4 = this->currentState->getSelected();
        
                    if (idx4!=idx1){
                        min4 = findNearestWay();
                    }
                }    
        
            }
        
        
            if (min2<mini){
                mini=min2;
                idx=idx2;
            }
            if (min3<mini){
                mini=min3;
                idx=idx3;
            }
            if (min4<mini){
                mini=min4;
                idx=idx4;
            }
        
            while (this->currentState->getSelected()!=idx){
                Sel->apply(this->currentState,true);
            }
        }
        
        else{
            mini=findNearestWay();
        }
        
        return mini;
    }
    
    void TrueIA::setIterateurs (int i, int j, int k){
        this->ite1=i;
        this->ite2=j;
        this->ite3=k;
    }

}

