/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Element* FieldCreator::create (){
        
        Element* fi=new Field(id);
        fi->setTypeID(TypeID::FIELD);
        return fi;
    }
    
    FieldCreator::FieldCreator(FieldTypeID id){
        this->id=id;
    }
}