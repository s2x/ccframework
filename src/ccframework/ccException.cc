/*
 * ccException.cpp
 *
 *  Created on: 30-09-2013
 *      Author: piotr
 */

#include "../include/ccframework/ccException.h"

namespace ccFramework {
const std::string ccException::ERROR_UNAUTHORIZED = "401";
const std::string ccException::ERROR_FORBIDDEN = "403";
const std::string ccException::ERROR_NOT_FOUND = "404";
const std::string ccException::ERROR_INTERNAL_SERVER_ERROR = "500";


const std::string ccException::ERROR_MSG_INTERNAL_SERVER_ERROR = "Internal Server Error";
const std::string ccException::ERROR_MSG_FORBIDDEN = "Forbidden";

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
