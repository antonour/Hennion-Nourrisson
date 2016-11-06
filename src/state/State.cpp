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
    
    void State::setElementFactory(ElementFactory* f){
        this->factory=f;
    }

    std::vector<Element*> State::getMobileElements (){
        return this->elements;
    }
    
    Element* State::getMobileElement (int idx){
        return this->elements[idx];
    }
    
    std::vector<Element*> State::getStaticElements (){
        return this->background;
    }
    
    Element* State::getStaticElement (int idx){
        return this->background[idx];
    }
    
    void State::killFowls(){
        for (Element* proc : this->elements){
            Fowl *fo;
            fo=reinterpret_cast<Fowl*>(proc);
            fo->setFowlStatus(FowlStatus::DEAD);
        }
        this->notifyObservers(new StateEvent(FOWL_DEAD),this->elements);
    }
    
    void State::loadLevel (const std::string& file_name){
        int a=1;
        int b=10;
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
                            background.push_back(factory->create(contenu,false));
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
            this->notifyObservers(new StateEvent(FILEMAP_LOADED),this->background);
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
                            garb->setX(125*k);
                            k++;
                            if (k==40){
                                l++;
                                k=0;
                            }
                            garb->setY(97*l);
                            this->elements.push_back(garb);
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
            this->notifyObservers(new StateEvent(FILECHAR_LOADED),this->elements);
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
}