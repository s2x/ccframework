/*
 * ccRole.cpp
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#include "ccRole.h"

namespace ccFramework {

ccRole::ccRole(std::string name, ccRole *parent) {
	// TODO Auto-generated constructor stub
	this->parent = parent;
	this->name = name;
}

ccRole* ccRole::getParent() {
	return parent;
}

std::string ccRole::getName(){
	return name;
}

void ccRole::setParent(ccRole* parent) {
	this->parent = parent;
}

ccRole::~ccRole() {
	// TODO Auto-generated destructor stub
}

} /* namespace ccFramework */
