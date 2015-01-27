/*
 * ccYamlSessionProvider.h
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#ifndef CCYAMLSESSIONPROVIDER_H_
#define CCYAMLSESSIONPROVIDER_H_

#include "ccSessionProvider.h"
#include "yaml-cpp/yaml.h"
#include <iostream>

namespace ccFramework {

class ccYamlSessionProvider: public ccSessionProvider {
protected:
	std::string session_file;
	std::string session_dir;
public:
	ccYamlSessionProvider(std::string config_string): ccSessionProvider(config_string){
		this->session_dir = config_string;
	}
	virtual bool hasSession(std::string id);
	virtual YAML::Node load(std::string id);
	virtual bool save(std::string id, YAML::Node data);
	std::string getSessionFilename(std::string id);
};

} /* namespace ccFramework */

#endif /* CCYAMLSESSIONPROVIDER_H_ */
