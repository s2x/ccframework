#include "interfaces/ccConfigProviderInterface.h"
#include <boost/property_tree/ini_parser.hpp>

#ifndef CCINICONFIGPROVIDER_H_
#define CCINICONFIGPROVIDER_H_
namespace ccFramework {
class ccIniConfigProvider: public ccConfigProviderInterface {

public:
    using ccConfigProviderInterface::ccConfigProviderInterface;

    void load()
    {
        std::stringstream ss(this->dataSource->getContent());
        boost::property_tree::read_ini(
            ss,
            this->data
        );
        this->loaded = true;
    }
    
    void save(){
        std::stringstream tmp_data;
        
        boost::property_tree::write_ini(
            tmp_data,
            this->data
        );
        
        this->dataSource->setContent(tmp_data.str());    
    }
    
    void set(boost::property_tree::ptree data){
        this->data = data;
    }
    
    boost::property_tree::ptree get(bool reload = false){
        if (this->loaded == false || reload) {
            this->load();
        }
        return this->data;
    }
};
}
#endif
