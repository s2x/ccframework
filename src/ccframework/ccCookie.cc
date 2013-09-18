/*
 * ccCookie.cpp
 *
 *  Created on: 12-09-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccCookie::ccCookie(std::string name, std::string value) {
	// TODO Auto-generated constructor stub
	this->name = name;
	this->value = value;
	this->secure = false;
	this->expires = 0;
	this->path = "/";
}

ccCookie::~ccCookie() {
	// TODO Auto-generated destructor stub
}

} /* namespace ccFramework */
