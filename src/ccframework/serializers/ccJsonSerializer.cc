//
// Created by piotr on 13.07.15.
//

#include "ccJsonSerializer.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>

using namespace rapidjson;

namespace ccFramework {

    std::string ccJsonSerializer::Dump(ccArray data) {
        StringBuffer s;
        Writer<StringBuffer> writer(s);

        writer.StartObject();

        std::vector<ccArray *> childs = data.getChildrens();
        for (std::vector<ccArray *>::iterator it = childs.begin();
             it != childs.end(); ++it) {
            ccJsonSerializer::_parseArray(*it, &writer);
        }
        writer.EndObject();
        return s.GetString();
    }

    ccArray ccJsonSerializer::Load(std::string string) {
        return ccArray();
    }

    void ccJsonSerializer::_parseArray(ccArray *data, rapidjson::Writer<StringBuffer> *writer) {

        std::vector<ccArray *> childs = data->getChildrens();

        switch (data->getType()) {
            case ccArray::TYPE_ARRAY: {
                writer->String(data->getName().c_str());
                writer->StartArray();
                for (std::vector<ccArray *>::iterator it = childs.begin();
                     it != childs.end(); ++it) {
                    ccJsonSerializer::_parseArray(*it, writer);
                }
                writer->EndArray();

            }
                break;
            case ccArray::TYPE_LIST: {
                writer->String(data->getName().c_str());
                writer->StartObject();
                for (std::vector<ccArray *>::iterator it = childs.begin();
                     it != childs.end(); ++it) {
                    ccJsonSerializer::_parseArray(*it, writer);
                }
                writer->EndObject();

            }
                break;

            case ccArray::TYPE_VALUE: {
                writer->String(data->getName().c_str());
                writer->String(data->getValue().c_str());
            }
                break;

            case ccArray::TYPE_NOT_SET: {
                writer->String(data->getName().c_str());
                writer->Null();
            }
                break;
        }
    }
}
