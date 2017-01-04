/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../webservices.hpp"

namespace webservices{
UserService::UserService (UserDB& userDB) : AbstractService("/user"),
    userDB(userDB) {
    
}

HttpStatus UserService::get (Json::Value& out, int id) const {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus UserService::post (const Json::Value& in, int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

HttpStatus UserService::remove (int id) {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

}