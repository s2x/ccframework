/*
 * ccConfig.h
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#ifndef CCCONFIG_H_
#define CCCONFIG_H_

namespace ccFramework {

class ccConfig {
	static std::map<std::string, ccConfigLoader*>configs;
public:
	ccConfig();
	virtual ~ccConfig();
	static ccConfigLoader *getInstance(std::string name = "");
};

} /* namespace ccFramework */
#endif /* CCCONFIG_H_ */
