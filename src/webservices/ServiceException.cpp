/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../webservices.hpp"

namespace webservices{
    
    ServiceException::ServiceException (HttpStatus status, std::string msg){
        
    }
    
    HttpStatus ServiceException::status () const{
        
    }
    
    const char* ServiceException::what () const{
        
    }
    
}