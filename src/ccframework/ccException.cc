/*
 * ccException.cpp
 *
 *  Created on: 30-09-2013
 *      Author: piotr
 */

#include "../include/ccframework/ccException.h"

namespace ccFramework {

ccException::ccException(std::string code, std::string msg) {
	// TODO Auto-generated constructor stub
	this->code = code;
	this->msg = msg;
}

std::string ccException::getCode(){
	return code;
}

std::string ccException::getMessage(){
	return msg;
}

ccException::~ccException() {
	// TODO Auto-generated destructor stub
}

} /* namespace ccFramework */
