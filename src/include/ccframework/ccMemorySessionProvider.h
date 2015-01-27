/*
 * ccMemorySessionProvider.h
 *
 *  Created on: 27-01-2015
 *      Author: piotr
 */

#ifndef CCMEMORYSESSIONPROVIDER_H_
#define CCMEMORYSESSIONPROVIDER_H_
#include <map>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include <ctime>
#include "ccClassDeclarations.h"
#include "ccSessionProvider.h"

namespace ccFramework {

class ccMemorySessionProvider: public ccSessionProvider {
protected:
	std::map<std::string, YAML::Node> sessions;
	std::map<std::string, std::time_t> last_updates;
public:
	ccMemorySessionProvider(std::string config_string): ccSessionProvider(config_string) {};
	bool hasSession(std::string id);
	YAML::Node load(std::string id);
	bool save(std::string id, YAML::Node data);


};

} /* namespace ccFramework */

#endif /* CCMEMORYSESSIONPROVIDER_H_ */
