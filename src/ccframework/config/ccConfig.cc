/*
 * ccConfig.cpp
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccConfig::ccConfig() {
	// TODO Auto-generated constructor stub

}

ccConfig::~ccConfig() {
	// TODO Auto-generated destructor stub
}

ccConfigLoader* ccConfig::getInstance(std::string name) {
	return new ccConfigLoader("");
	//return this->configs[name];
}

} /* namespace ccFramework */
