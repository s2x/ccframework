/*
 * ccSessionProvider.cc
 *
 *  Created on: 26-01-2015
 *      Author: piotr
 */

#include "ccSessionProvider.h"

namespace ccFramework {

ccSessionProvider::ccSessionProvider(std::string config_string) {
	// TODO Auto-generated constructor stub
	this->id="";
}

bool ccSessionProvider::hasSession(std::string id) {
	if (this->id.compare(id) == 0) return true;
	return false;
}

YAML::Node ccSessionProvider::load(std::string id) {
	this->id = id;
	YAML::Node ret;
	return ret;
}

bool ccSessionProvider::save(std::string id, YAML::Node data) {
	return true;
}

ccSessionProvider::~ccSessionProvider() {
}

} /* namespace ccFramework */
