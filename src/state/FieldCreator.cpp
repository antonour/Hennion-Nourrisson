/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Element* FieldCreator::create (std:: string st){
        
        Element* p=new Field(BIGBROWN1);
        return p;
    }
}