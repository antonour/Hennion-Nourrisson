// Generated by dia2code
#ifndef WEBSERVICES__VERSIONSERVICE__H
#define WEBSERVICES__VERSIONSERVICE__H

#include "../../extern/jsoncpp-0.10.5/include/json/json.h"

namespace webservices {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace webservices {

  /// class VersionService - 
  class VersionService : public webservices::AbstractService {
    // Operations
  public:
    VersionService ();
    HttpStatus get (Json::Value& out, int id) const;
  };

};

#endif
