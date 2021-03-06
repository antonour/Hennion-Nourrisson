/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"../state.hpp"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

namespace state{
    
    State::~State(){}
    
    int State::getNbWhiteDead(){
        return this->nbWhiteDead;
    }
    
    int State::getNbGreenDead(){
        return this->nbGreenDead;
    }
    
    void State::setNbWhiteDead(int nb){
        this->nbWhiteDead=nb;
    }
    
    void State::setNbGreenDead(int nb){
        this->nbGreenDead=nb;
    }
    
    void State::setElementFactory(ElementFactory* f){
        this->factory=f;
    }

    std::vector<Element*> State::getMobileElements (){
        return this->elements;
    }
    
    Element* State::getMobileElement (int idx){
        return this->elements.at(idx);
    }
    
    std::vector<Element*> State::getStaticElements (){
        return this->background;
    }
    
    Element* State::getStaticElement (int idx){
        return this->background[idx];
    }
    
    void State::resetState(){
        this->elements.clear();
        this->background.clear();
        this->weapons.clear();
        this->nbGreenDead=0;
        this->nbWhiteDead=0;
    }
    
    int State::getSelected(){
        int i=0;
        for (Element* el: this->elements){
            Fowl* f=reinterpret_cast<Fowl*>(el);
            if (f->isSelected()){
                return i;
            }
            i++;
        }
        throw std::runtime_error("Poule non sélectionnée");
    }
    
    void State::killFowl(){
        int i=0;
        for (Element* proc : this->elements){
            Fowl *fo;
            fo=reinterpret_cast<Fowl*>(proc);
            if (fo->isSelected()==true && (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT || fo->getFowlStatus()==FowlStatus::ALIVE_RIGHT)){
                if (fo->getFowlStatus()==FowlStatus::ALIVE_LEFT){
                    fo->setDirection(state::Direction::OUEST);
                }
                else{
                    fo->setDirection(state::Direction::EST);
                }
                fo->setFowlStatus(FowlStatus::HITTING);
                this->setMobileElement(fo,i);
            }
            i++;
        }
        this->notifyObservers(new StateEvent(FOWL_HITTING),this->elements,this->weapons);
    }
    
    void State::loadLevel (const std::string& file_name){
        int a=1;
        int b=10;
        int k=0,l=0;
        ifstream fichier1(file_name, ios::in);
        if(fichier1){
            int nbrelignes=0;
            string line;
            while(getline(fichier1,line)){
                nbrelignes++;
            }
            a=nbrelignes;
            fichier1.close();
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
        ifstream fichier2(file_name, ios::in);
        if(fichier2){
            int nbrechar=0;
            char letter;
            while(fichier2.get(letter)){
                nbrechar++;
            }
            b=(nbrechar+1)/a;
            fichier2.close();
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
        ifstream fichier3(file_name, ios::in);
        if(fichier3){
            char contenu1,contenu2,poubelle;
            string contenu="";
            for(int j=1;j<a+1;j++){
                for(int i=1;i<b+1;i++){
                    if(i<b){
                        if(i%3==1){
                            fichier3.get(contenu1);
                            contenu+=contenu1;
                        }
                        if(i%3==2){
                            fichier3.get(contenu2);
                            contenu+=contenu2;
                        }
                        if(i%3==0){
                            Element * terr = this->factory->create(contenu,false);
                            terr->setX(125*k);
                            k++;
                            if (k==40){
                                l++;
                                k=0;
                            }
                            terr->setY(97*l);
                            this->background.push_back(terr);
                            fichier3.get(poubelle);
                            contenu="";
                        }
                    }
                    if(i==b){
                        fichier3.get(poubelle);
                    }
                }
            }
            //cout << contenu << endl;
            fichier3.close();
            this->setNbGreenDead(0);
            this->setNbWhiteDead(0);
            this->notifyObservers(new StateEvent(FILEMAP_LOADED),this->background,this->weapons);
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
    }
    
    void State::loadChar (const std::string& file_name){
        int a=1;
        int b=10;
        int k=0;
        int l=0;
        ifstream fichier1(file_name, ios::in);
        if(fichier1){
            int nbrelignes=0;
            string line;
            while(getline(fichier1,line)){
                nbrelignes++;
            }
            a=nbrelignes;
            fichier1.close();
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
        ifstream fichier2(file_name, ios::in);
        if(fichier2){
            int nbrechar=0;
            char letter;
            while(fichier2.get(letter)){
                nbrechar++;
            }
            b=(nbrechar+1)/a;
            fichier2.close();
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
        ifstream fichier3(file_name, ios::in);
        if(fichier3){
            char contenu1,contenu2,poubelle;
            string contenu="";
            for(int j=1;j<a+1;j++){
                for(int i=1;i<b+1;i++){
                    if(i<b){
                        if(i%3==1){
                            fichier3.get(contenu1);
                            contenu+=contenu1;
                        }
                        if(i%3==2){
                            fichier3.get(contenu2);
                            contenu+=contenu2;
                        }
                        if(i%3==0){
                            Element * garb = this->factory->create(contenu,true);
                            Element * weap = this->factory->create("02",true);
                            Weapon * w=reinterpret_cast<Weapon*>(weap);
                            garb->setX(125*k);
                            weap->setX(125*k);
                            k++;
                            if (k==40){
                                l++;
                                k=0;
                            }
                            garb->setY(97*l);
                            weap->setY(97*l);
                            this->elements.push_back(garb);
                            this->weapons.push_back(w);
                            fichier3.get(poubelle);
                            contenu="";
                        }
                    }
                    if(i==b){
                        fichier3.get(poubelle);
                    }
                }
            }
            fichier3.close();
            this->notifyObservers(new StateEvent(FILECHAR_LOADED),this->elements,this->weapons);
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
    }
    
    void State::setMobileElement(Element* el, int idx){
        int i=0;
        std::vector<Element*> newlist;
        for (Element* parcours: this->elements){
            if (i==idx){
                newlist.push_back(el);
                i++;
            }
            else{
                newlist.push_back(parcours);
                i++;
            }
        }
        this->elements=newlist;
    }
    
    int State::selectNextFowl(bool keepview) {
        bool found=false;
        bool lastfound=false;
        int p=0,k=0;
        for (Element* el: this->elements){
            Fowl* f=reinterpret_cast<Fowl*>(el);
            if (found){
                if (f->getFowlColor()!=FowlColor::BLANK && f->getFowlStatus()!=FowlStatus::DEAD){
                    f->setSelected(true);
                    lastfound=true;
                    f->setMoveUnits(300);
                    this->setMobileElement(f,p);
                    if (!keepview){
                        this->notifyObservers(new StateEvent(StateEventID::FOWL_SELECTED),this->elements,this->weapons);
                    }
                    return p;
                }
            }
            else{
                if (f->isSelected()){
                    found=true;
                    f->setSelected(false);
                    f->setMoveUnits(0);
                    if (f->getFowlStatus()!=FowlStatus::HITTING && f->getFowlStatus()!=FowlStatus::DEAD){
                        f->setFowlStatus(FowlStatus::ALIVE_FACE);
                    }
                    if(keepview){
                        this->setMobileElement(f,p);
                    }
                    else{
                        this->setMobileElement(f,p);
                        this->notifyObservers(new StateEvent(StateEventID::FOWL_STOP),this->elements,this->weapons);
                    }
                }
            }
            p++;
        }
        if (found==false || lastfound==false){
                for (Element* e: this->elements){
                    Fowl* fo=reinterpret_cast<Fowl*>(e);
                    if (fo->getFowlColor()!=FowlColor::BLANK && fo->getFowlStatus()!=FowlStatus::DEAD){
                        fo->setSelected(true);
                        fo->setMoveUnits(300);
                        if (keepview){
                            this->setMobileElement(fo,k);
                        }
                        else{
                            this->setMobileElement(fo,k);
                            this->notifyObservers(new StateEvent(StateEventID::FOWL_SELECTED),this->elements,this->weapons);
                        }
                        return k;
                    }
                    k++;
                }
        }
        return 0;
    }
    
    std::vector<Weapon*> State::getWeaponElements(){
        return this->weapons;
    }
    
    Weapon* State::getWeaponElement(int idx){
        return this->weapons.at(idx);
    }
    
    void State::setWeaponElement(Weapon* we, int idx) {
        int i=0;
        std::vector<Weapon*> newlist;
        for (Weapon* parcours: this->weapons){
            if (i==idx){
                newlist.push_back(we);
                i++;
            }
            else{
                newlist.push_back(parcours);
                i++;
            }
        }
        this->weapons=newlist;
    }

    
    void State::selectWeapon(WeaponStatus status, int idx){
        Weapon* wea= new Weapon(status,false);
        this->setWeaponElement(wea,idx);
        this->setWeaponVisibility(true,idx);
        this->notifyObservers(new StateEvent(StateEventID::WEAPON_IN),this->elements,this->weapons);
    }
    
    void State::setWeaponVisibility(bool visible, int idx){
        int i=0;
        for (Weapon* parcours: this->weapons){
            if (i==idx){
                parcours->setVisibility(visible);
            }
            i++;
        }
    }
    
    void State::initializeWeaponAmmo(){
        int i=0;
        for (Weapon* parcours: this->weapons){
            if (i==0){ //Tronçonneuse
                parcours->setAmmoGreen(6);
                parcours->setAmmoWhite(6);
            }
            else if (i==1){ //Sabre Laser
                parcours->setAmmoGreen(2);
                parcours->setAmmoWhite(2);
            }
            else if (i==2){ // Hache
                parcours->setAmmoGreen(4);
                parcours->setAmmoWhite(4);
            }
            else if (i==3){ // Epee
                parcours->setAmmoGreen(5);
                parcours->setAmmoWhite(5);
            }
            else if (i==4){ // Sabre Ninja
                parcours->setAmmoGreen(3);
                parcours->setAmmoWhite(3);
            }
            else if (i==5){ // Prise Electrique
                parcours->setAmmoGreen(-1);
                parcours->setAmmoWhite(-1);
            }
            else if (i==6){ // Baguette Magique
                parcours->setAmmoGreen(1);
                parcours->setAmmoWhite(1);
            }
            i++;
        }
    }

}