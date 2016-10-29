/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Element* SpaceCreator::create (){
        
        Element* p=new Space(id);
        p->setTypeID(TypeID::SPACE);
        return p;
    }
    
    SpaceCreator::SpaceCreator(SpaceTypeID id){
        this->id=id;
    }
}