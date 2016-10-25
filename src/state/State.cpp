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
    
    std::vector<Element*> State::loadLevel (const std::string& file_name){
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
                            Element* var=factory->create(contenu,false);
                            background.push_back(var);
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
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
        
        return this->background;
    }
    
    std::vector<Element*> State::loadChar (const std::string& file_name){
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
                            Element* var=factory->create(contenu,true);
                            elements.push_back(var);
                            delete var;
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
        }
        else
            cerr << "Impossible to open that f***ing file" << endl;
        
        return this->elements;
    }
}