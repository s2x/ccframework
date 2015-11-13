#ifndef CCDATAPROVIDERINTERFACE_H_
#define CCDATAPROVIDERINTERFACE_H_
#include <iostream>

namespace ccFramework {
class ccDataProviderInterface {
protected:
    std::string content = "";
    bool is_loaded = false;
    
public:
    static const int OK = 0;
    static const int ERROR_READONLY = 1;
    static const int ERROR_WRITEOLNY = 2;
    static const int ERROR_NOT_FOUND = 3;

    virtual int setContent(std::string content, bool reload = false) = 0;
    virtual std::string getContent(bool reload = false) = 0;

};
}
#endif
