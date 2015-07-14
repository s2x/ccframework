//
// Created by piotr on 14.07.15.
//

#ifndef CCFRAMEWORK_CCJSONRESPONSE_H
#define CCFRAMEWORK_CCJSONRESPONSE_H

#include "ccArray.h"
#include "ccResponse.h"

namespace ccFramework {
    class ccJsonResponse: public ccResponse {

        ccArray _data;
    public:
        ccJsonResponse();
        ccJsonResponse(ccArray data);

        void setContent(ccArray data);
    };
}

#endif //CCFRAMEWORK_CCJSONRESPONSE_H
