/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Field::Field (FieldTypeID id){
        this->status=id;
        this->type=TypeID::FIELD;
    }
    
    Field::~Field(){}
    
    bool Field::isSpace () const{
        return false;
    }
    
    TypeID Field::getTypeID () const{
        return this->type;
    }
    
    FieldTypeID Field::getFieldTypeID (){
        return this->status;
    }
    
    void Field::setFieldTypeID (FieldTypeID id){
        this->status=id;
    }
    
}