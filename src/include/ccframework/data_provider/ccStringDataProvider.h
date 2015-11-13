#ifndef CCSTRINGDATAPROVIDER_H_
#define CCSTRINGDATAPROVIDER_H_

#include <iostream>
#include <fstream>
#include "interfaces/ccDataProviderInterface.h"
namespace ccFramework {
class ccStringDataProvider : public ccDataProviderInterface {
public:
    ccStringDataProvider(std::string content) {
        this->content = content;
    }
    
    std::string getContent(bool reload = false) {
        return this->content;
    }
    

    int setContent(std::string content, bool reload = false) {
        this->content = content;
        return content.length();
    }
};
}
#endif
