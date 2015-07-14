//
// Created by piotr on 14.07.15.
//

#include <ccJsonSerializer.h>
#include "ccJsonResponse.h"

namespace ccFramework {


    ccJsonResponse::ccJsonResponse() {
        this->setHeader("Content-type","application/json");
    }

    ccJsonResponse::ccJsonResponse(ccArray data) {
        this->setHeader("Content-type","application/json");
        this->_data = data;
        this->content = ccJsonSerializer::Dump(this->_data);
    }

    void ccJsonResponse::setContent(ccArray data) {
        this->_data = data;
        this->content = ccJsonSerializer::Dump(this->_data);
    }
}