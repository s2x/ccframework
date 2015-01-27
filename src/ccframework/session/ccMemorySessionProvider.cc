/*
 * ccMemorySessionProvider.cc
 *
 *  Created on: 27-01-2015
 *      Author: piotr
 */

#include "ccMemorySessionProvider.h"

namespace ccFramework {

bool ccMemorySessionProvider::hasSession(std::string id) {
	if (this->sessions.count(id)>0) return true;
	return false;
}

YAML::Node ccMemorySessionProvider::load(std::string id) {
	if (this->hasSession(id)) return this->sessions[id];

	YAML::Node empty_node;
	return empty_node;
}

bool ccMemorySessionProvider::save(std::string id,
		YAML::Node data) {
	this->sessions[id] = data;
	this->last_updates[id] = std::time(NULL);
	//std::time_t result = std::time(nullptr);
	return true;
}

} /* namespace ccFramework */
