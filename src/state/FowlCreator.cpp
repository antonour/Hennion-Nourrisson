/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../state.hpp"

namespace state{
    
    Element* FowlCreator::create (){
        
        Element* f=new Fowl(color,status);
        f->setTypeID(TypeID::FOWL);
        return f;
    }
    
    FowlCreator::FowlCreator(FowlColor color,FowlStatus status){
        this->color=color;
        this->status=status;
    }
}