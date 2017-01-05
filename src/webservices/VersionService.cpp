/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../webservices.hpp"

namespace webservices{
    
    VersionService::VersionService () : AbstractService("/version") {
    
	}
    
    HttpStatus VersionService::get (Json::Value& out, int id) const{
        
    }
    
}
