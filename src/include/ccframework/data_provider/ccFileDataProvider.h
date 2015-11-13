#ifndef CCFILEDATAPROVIDER_H_
#define CCFILEDATAPROVIDER_H_

#include <iostream>
#include <fstream>
#include "interfaces/ccDataProviderInterface.h"
namespace ccFramework {
class ccFileDataProvider : public ccDataProviderInterface {
protected:
    std::string filename;

public:
    ccFileDataProvider(std::string filename) {
        this->filename = filename;
    }
    
    std::string getContent(bool reload = false) {
        if (reload || this->is_loaded == false) {
            std::fstream file(this->filename.c_str(), std::fstream::in);
            if(file.is_open())
            {
                std::getline(file, this->content, '\0') ;
            }
        }
        return this->content;
    }
    

    int setContent(std::string content, bool reload = false) {
        std::fstream file(this->filename.c_str(), std::fstream::out);
        if(file.is_open())
        {
            file.write(content.c_str(), content.length());
            return content.length();
        }
        return -1;
    }
};
}
#endif
