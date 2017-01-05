// Generated by dia2code
#ifndef WEBSERVICES__ABSTRACTSERVICE__H
#define WEBSERVICES__ABSTRACTSERVICE__H

#include <string>
#include "../../extern/jsoncpp-0.10.5/include/json/json.h"

#include "HttpStatus.h"

namespace webservices {

  /// class AbstractService - 
  class AbstractService {
    // Attributes
  protected:
    std::string pattern;
    // Operations
  public:
    AbstractService (const std::string& pattern);
    virtual ~AbstractService ();
    const std::string& getPattern () const;
    void setPattern (const std::string& pattern);
    virtual HttpStatus get (Json::Value& out, int id) const;
    virtual HttpStatus post (const Json::Value& in, int id);
    virtual HttpStatus put (Json::Value& out, const Json::Value& in);
    virtual HttpStatus remove (int id);
  };

};

#endif
