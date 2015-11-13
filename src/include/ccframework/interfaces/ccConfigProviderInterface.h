#ifndef CCCONFIGPROVIDERINTERFACE_H_
#define CCCONFIGPROVIDERINTERFACE_H_

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include "interfaces/ccDataProviderInterface.h"

namespace ccFramework {
class ccConfigProviderInterface {
protected:
    ccDataProviderInterface *dataSource;
    boost::property_tree::ptree data;
    bool loaded = false;
public:

    ccConfigProviderInterface(ccDataProviderInterface *dataSource) {
        this->dataSource = dataSource;
    }
    
    ccDataProviderInterface *getDataProvider() {
        return this->dataSource;
    }
    
    virtual void load() = 0;
    virtual void save() = 0;
    virtual void set(boost::property_tree::ptree data) = 0;
    virtual boost::property_tree::ptree get(bool reload = false) = 0;
};
}
#endif
