/*
 * ccResource.cpp
 *
 *  Created on: 25-09-2013
 *      Author: piotr
 */

#include "ccResource.h"

namespace ccFramework {

ccResource::ccResource(std::string name, ccResource *parent) {
	// TODO Auto-generated constructor stub
	this->parent = parent;
	this->name = name;
}

ccResource* ccResource::getParent() {
	return parent;
}

std::string ccResource::getName(){
	return name;
}

void ccResource::setParent(ccResource* parent) {
	this->parent = parent;
}

ccResource::~ccResource() {
	// TODO Auto-generated destructor stub
}

} /* namespace ccFramework */
