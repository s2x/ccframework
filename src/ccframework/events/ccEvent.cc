/*
 * ccEvent.cpp
 *
 *  Created on: 17-09-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccEvent::ccEvent(std::string name, void *ptr) {
	// TODO Auto-generated constructor stub
	this->name = name;
	this->func_poiner = (void *(*)(std::map<std::string, void *>))ptr;
}

ccEvent::~ccEvent() {
	// TODO Auto-generated destructor stub
}

std::string ccEvent::getName(){
	return this->name;
}


void ccEvent::call(std::map<std::string, void*> allocator) {
	this->func_poiner(allocator);
}

} /* namespace ccFramework */
