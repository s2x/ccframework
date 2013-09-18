/*
 * ccResponse.cpp
 *
 *  Created on: 30-07-2013
 *      Author: piotr
 */

#include "ccframework/ccFramework.h"

namespace ccFramework {

ccResponse::ccResponse() {
	// TODO Auto-generated constructor stub
	this->setHeader("Content-type","text/html");
}

ccResponse::ccResponse(std::string content) {
	this->setHeader("Content-type","text/html");
	this->setContent(content);
}


ccResponse::~ccResponse() {
	// TODO Auto-generated destructor stub

	while (this->cookies.size()) {
		delete this->cookies.begin()->second;
		this->cookies.erase(this->cookies.begin());
	}

}

} /* namespace ccFramework */

