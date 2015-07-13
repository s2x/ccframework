//
// Created by piotr on 13.07.15.
//

#ifndef CCFRAMEWORK_CCBASESERIALIZER_H
#define CCFRAMEWORK_CCBASESERIALIZER_H


#include "ccArray.h"


namespace ccFramework {
    class ccBaseSerializer {
    public:
        static std::string Dump(ccArray data);
        static ccArray Load(std::string);
    };
}

#endif //CCFRAMEWORK_CCBASESERIALIZER_H
