#include "interfaces/ccConfigProviderInterface.h"
#include <boost/property_tree/info_parser.hpp>

#ifndef CCINFOCONFIGPROVIDER_H_
#define CCINFOCONFIGPROVIDER_H_
namespace ccFramework {
class ccInfoConfigProvider: public ccConfigProviderInterface {

public:
    using ccConfigProviderInterface::ccConfigProviderInterface;

    void load()
    {
        std::stringstream ss(this->dataSource->getContent());
        boost::property_tree::read_info(
            ss,
            this->data
        );
        this->loaded = true;
    }
    
    void save(){
        std::stringstream tmp_data;
        
        boost::property_tree::write_info(
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
