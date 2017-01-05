/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../webservices.hpp"

namespace webservices{
    
    void ServicesManager::registerService (std::unique_ptr<AbstractService> service){
        
    }
    
    AbstractService* ServicesManager::findService (const std::string& url) const{
        
    }
    
    HttpStatus ServicesManager::queryService (std::string& out, const std::string& in, const std::string& url, const std::string& method){
        
    }
    
}