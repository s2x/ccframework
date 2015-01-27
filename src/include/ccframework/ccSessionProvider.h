/*
 * ccSessionProvider.h
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#ifndef CCSESSIONPROVIDER_H_
#define CCSESSIONPROVIDER_H_

#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

namespace ccFramework {

class ccSessionProvider {
protected:
	std::string id;
public:
	ccSessionProvider(std::string config_string);

	virtual bool hasSession(std::string id);
	virtual YAML::Node load(std::string id);
	virtual bool save(std::string id, YAML::Node data);
	virtual ~ccSessionProvider();

};

} /* namespace ccFramework */

#endif /* CCSESSIONPROVIDER_H_ */
