//
// Created by piotr on 13.07.15.
//

#ifndef CCFRAMEWORK_CCJSONSERIALIZER_H
#define CCFRAMEWORK_CCJSONSERIALIZER_H

#include "ccBaseSerializer.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "ccArray.h"
namespace ccFramework {

    class ccJsonSerializer: public ccBaseSerializer {
    protected:
        static void _parseArray(ccArray *data, rapidjson::Writer<rapidjson::StringBuffer> *writer);
    public:
        static std::string Dump(ccArray data);
        static ccArray Load(std::string);
    };

}

#endif //CCFRAMEWORK_CCJSONSERIALIZER_H
