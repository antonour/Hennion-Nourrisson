/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"



namespace state{
    
    Element::Element (){
    this->type=SPACE;
    this->X=0;
    this->Y=0;
    }

    Element::~Element(){}
    
    int Element::getX () const{
        return this->X;
    }
    
    int Element::getY () const{
        return this->Y;
    }
     
    void Element::setX (int x){
        this->X=x;
    }
    
    void Element::setY (int y){
        this->Y=y;
    }
    
    void Element::setTypeID(TypeID id){
        this->type=id;
    }
    /*TypeID Element::getTypeID() const{
        return this->type;
    }*/
    
    int Element::getIDXbyXY (){
        
        int numeroLigne = this->Y/97;
        int numeroColonne= this->X/125;
        
        int idx = (40*numeroLigne+numeroColonne);
        
        return idx;       
        
    }
}
